// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SDieAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USDieAction : public USAction
{
	GENERATED_BODY()

	USDieAction();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Anim")
	TArray<TObjectPtr<UAnimMontage>> DieAnimMontages;

public:
	virtual bool StartAction(AActor* instigator) override;
	virtual bool StopAction(AActor* instigator) override;
};
