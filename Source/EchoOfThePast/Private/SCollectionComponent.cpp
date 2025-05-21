// Fill out your copyright notice in the Description page of Project Settings.


#include "SCollectionComponent.h"

#include "SDialogComponent.h"
#include "Camera/CameraComponent.h"

#include "SObjectActor.h"
#include "SPlayerCharacter.h"
#include "SDialogComponent.h"

// Sets default values for this component's properties
USCollectionComponent::USCollectionComponent():
	TraceDistance(100.0f),
	bIsSelected(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USCollectionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USCollectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	bIsSelected = PerformRayCast();

}

bool USCollectionComponent::PerformRayCast()
{
    // 获取当前拥有此组件的角色
    AActor* Owner = GetOwner();
    if (!Owner) return false;

    // 获取相机组件
    UCameraComponent* Camera = Owner->FindComponentByClass<UCameraComponent>();
    if (!Camera) return false;

    // 获取相机位置和朝向
    FVector CameraLocation = Camera->GetComponentLocation();
    FVector CameraForward = Camera->GetForwardVector();

    // 射线的终点位置（相机前方一定距离）
    FVector EndLocation = CameraLocation + CameraForward * TraceDistance;

    // 射线检测
    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(Owner);  // 忽略自己

    // 执行射线检测
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECC_Visibility, CollisionParams);

    // 绘制射线（仅用于调试）
    if (bHit)
    {
        // 如果有碰撞，绘制红色线
        //DrawDebugLine(GetWorld(), CameraLocation, HitResult.ImpactPoint, FColor::Red, false, 3, 0, 5);

        AActor* HitActor = HitResult.GetActor();
        if (HitActor)
        {
            if(HitActor->IsA(ASObjectActor::StaticClass()))
            {
                auto r = Cast<ASObjectActor>(HitActor);

                if(SelectedObject!=r)
                {
                    r->OnSelected(GetOwner());
                    if(SelectedObject)
						SelectedObject->OnOffSelected(GetOwner());
                    SelectedObject = r;

                    //Add subtitle to screen
                    auto player = Cast<ASPlayerCharacter>(Owner);
                    player->FindComponentByClass<USDialogComponent>()->SetItemText(r->GetItemName());
                }
                return true;
            }
        }
    }
    else
    {
        if(SelectedObject)
        {
            SelectedObject->OnOffSelected(GetOwner());
            SelectedObject = nullptr;
            auto player = Cast<ASPlayerCharacter>(Owner);
            player->FindComponentByClass<USDialogComponent>()->SetItemText(FText());
        }
        // 如果没有碰撞，绘制绿色线
        //DrawDebugLine(GetWorld(), CameraLocation, EndLocation, FColor::Green, false, 3, 0, 5);
        return false;
    }
    return false;
}

