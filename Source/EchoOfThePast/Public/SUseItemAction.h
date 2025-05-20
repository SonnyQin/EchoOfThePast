// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SUseItemAction.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USUseItemAction : public USAction
{
	GENERATED_BODY()
public:
	USUseItemAction();

protected:
	virtual bool StartAction(AActor* instigator) override;
	virtual bool StopAction(AActor* instigator) override;
};
