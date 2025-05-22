// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SBookItem.generated.h"

/**
 * 
 */


//∆Ù”√CourageLevel
UCLASS()
class ECHOOFTHEPAST_API USBookItem : public USItem
{
	GENERATED_BODY()

protected:
	virtual bool Use(AActor* Instigator) override;
	
};
