// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SBTTask_Wander.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USBTTask_Wander : public UBTTaskNode
{	
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Wander")
		float WanderRadius = 800.0f;
	UPROPERTY(EditAnywhere, Category = "Wander")
		float MinDistance = 300.0f;

	UPROPERTY(EditAnywhere, Category = "Wander")
		float WanderSpeed = 150;
};
