// Fill out your copyright notice in the Description page of Project Settings.

#include "SStoryGameMode.h"

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ASStoryGameMode::ASStoryGameMode()
{
}

void ASStoryGameMode::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);

    PlayerController->bShowMouseCursor = true;//显示鼠标

    PlayerController->SetIgnoreLookInput(true);//设置鼠标不控制转向


    // 播放背景音乐
    if (BackgroundMusic)
    {
        UGameplayStatics::PlaySound2D(GetWorld(), BackgroundMusic);
    }

    // 创建并添加 Widget
    if (StoryWidgetClass)
    {
        StoryWidget = CreateWidget<UUserWidget>(GetWorld(), StoryWidgetClass);
        if (StoryWidget)
        {
            StoryWidget->AddToViewport();

            // 初始化透明度为0（隐藏）
            if (UTextBlock* TextBlock = Cast<UTextBlock>(StoryWidget->GetWidgetFromName("StoryText")))
            {
                TextBlock->SetRenderOpacity(0.f);
            }
        }
    }

    // 初始化故事文本
    StoryLines = {
        TEXT("Shiteater number one"),
        TEXT("Shiteater number two"),
        TEXT("Shiteater number three"),
        TEXT("Shiteater number four")
    };

    CurrentLineIndex = -1;
    ShowNextLine();
}

void ASStoryGameMode::ShowNextLine()
{
    CurrentLineIndex++;
    if (CurrentLineIndex < StoryLines.Num())
    {
        if (UTextBlock* TextBlock = Cast<UTextBlock>(StoryWidget->GetWidgetFromName("StoryText")))
        {
            TextBlock->SetRenderOpacity(0.f);
            TextBlock->SetText(FText::FromString(StoryLines[CurrentLineIndex]));
            FadeText(TextBlock);
        }
    }
    else
    {
        UGameplayStatics::OpenLevel(this, FName("MainLevel"));
    }
}

void ASStoryGameMode::FadeText(UTextBlock* TextBlock)
{
    if (!TextBlock) return;

    float FadeInTime = 1.0f;
    float DisplayTime = 3.0f;
    float FadeOutTime = 1.0f;
    float ExtraPauseTime = 0.5f;

    float TickInterval = 0.005f; // 更高帧率
    int32 FadeStepsIn = FadeInTime / TickInterval;
    int32 FadeStepsOut = FadeOutTime / TickInterval;

    // 淡入
    for (int32 i = 1; i <= FadeStepsIn; ++i)
    {
        float Alpha = i / float(FadeStepsIn);
        FTimerHandle Handle;
        GetWorld()->GetTimerManager().SetTimer(Handle, [TextBlock, Alpha]() {
            TextBlock->SetRenderOpacity(Alpha);
            }, i * TickInterval, false);
    }

    // 淡出
    FTimerHandle HoldHandle;
    GetWorld()->GetTimerManager().SetTimer(HoldHandle, [this, TextBlock, FadeStepsOut, TickInterval]() {
        for (int32 i = 1; i <= FadeStepsOut; ++i)
        {
            float Alpha = 1.f - (i / float(FadeStepsOut));
            FTimerHandle Handle;
            GetWorld()->GetTimerManager().SetTimer(Handle, [TextBlock, Alpha]() {
                TextBlock->SetRenderOpacity(Alpha);
                }, i * TickInterval, false);
        }
        }, FadeInTime + DisplayTime, false);

    // 下一句延迟执行
    GetWorld()->GetTimerManager().SetTimer(
        StoryTimerHandle,
        this,
        &ASStoryGameMode::ShowNextLine,
        FadeInTime + DisplayTime + FadeOutTime + ExtraPauseTime,
        false
    );
}