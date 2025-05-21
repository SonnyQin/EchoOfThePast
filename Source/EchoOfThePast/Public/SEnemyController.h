// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SEnemyController.generated.h"

class UBehaviorTree;
class ASPlayerCharacter;

UCLASS()
class ECHOOFTHEPAST_API ASEnemyController : public AAIController
{
	GENERATED_BODY()
public:
	ASEnemyController();

protected:
	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	ASPlayerCharacter* TargetPlayer;
};
