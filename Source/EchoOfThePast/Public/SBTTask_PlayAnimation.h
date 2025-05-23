// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SBTTask_PlayAnimation.generated.h"

class UAnimMontage;
UCLASS()
class ECHOOFTHEPAST_API USBTTask_PlayAnimation : public UBTTaskNode
{
	GENERATED_BODY()

	USBTTask_PlayAnimation();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
		TObjectPtr<UAnimMontage> AnimMontage;

	bool bIsPlaying;
	
};
