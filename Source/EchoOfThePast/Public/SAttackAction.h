// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SAttackAction.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USAttackAction : public USAction
{
	GENERATED_BODY()

public:
	USAttackAction();

	UFUNCTION(BlueprintCallable, Category = "Actions")
		virtual bool StartAction(AActor* instigator) override;
	UFUNCTION(BlueprintCallable, Category = "Actions")
		virtual bool StopAction(AActor* instigator) override;

};
