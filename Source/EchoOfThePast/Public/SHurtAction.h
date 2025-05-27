// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SHurtAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USHurtAction : public USAction
{
	GENERATED_BODY()

		USHurtAction();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Anim")
		TArray<TObjectPtr<UAnimMontage>> HurtAnimMontages;

public:
	virtual bool StartAction(AActor* instigator) override;
	virtual bool StopAction(AActor* instigator) override;
};
