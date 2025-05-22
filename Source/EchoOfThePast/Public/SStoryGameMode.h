#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SStoryGameMode.generated.h"

class UUserWidget;
class USoundBase;
class UTextBlock;

UCLASS()
class ECHOOFTHEPAST_API ASStoryGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASStoryGameMode();

    virtual void BeginPlay() override;

protected:
    UPROPERTY(EditAnywhere, Category = "Story")
        TSubclassOf<UUserWidget> StoryWidgetClass;

    UPROPERTY(VisibleAnywhere, Category = "Story")
        UUserWidget* StoryWidget;

    UPROPERTY(EditAnywhere, Category = "Story")
        USoundBase* BackgroundMusic;

    TArray<FString> StoryLines;
    int32 CurrentLineIndex = 0;

    FTimerHandle StoryTimerHandle;

    void ShowNextLine();
    void FadeText(UTextBlock* TextBlock);
};
