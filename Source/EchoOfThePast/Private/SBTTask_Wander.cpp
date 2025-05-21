// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTTask_Wander.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"


class UNavigationSystemV1;

EBTNodeResult::Type USBTTask_Wander::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AICon = OwnerComp.GetAIOwner();
    if (!AICon) return EBTNodeResult::Failed;

    APawn* AIPawn = AICon->GetPawn();
    if (!AIPawn) return EBTNodeResult::Failed;

    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (!NavSys) return EBTNodeResult::Failed;

    FVector Origin = AIPawn->GetActorLocation();
    FNavLocation RandomPoint;

    // 多次尝试采样
    for (int i = 0; i < 10; ++i)
    {
        float Radius = FMath::FRandRange(MinDistance, WanderRadius);
        if (NavSys->GetRandomReachablePointInRadius(Origin, Radius, RandomPoint))
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("WanderTarget")), RandomPoint);
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}
