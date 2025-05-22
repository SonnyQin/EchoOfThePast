// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SHelmetItem.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USHelmetItem : public USItem
{
	GENERATED_BODY()

protected:
	virtual bool Use(AActor* Instigator) override;
	
};
