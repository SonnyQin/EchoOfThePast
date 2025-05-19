// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SCollectAction.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USCollectAction : public USAction
{
	GENERATED_BODY()

	USCollectAction();

public:
	virtual bool StartAction(AActor* instigator) override;
	virtual bool StopAction(AActor* instigator) override;
	
};
