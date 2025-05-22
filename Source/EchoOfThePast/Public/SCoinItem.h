// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SCoinItem.generated.h"

/**
 * 
 */

//µ÷µ≤“ª¥Œ÷¬√¸…À∫¶
UCLASS()
class ECHOOFTHEPAST_API USCoinItem : public USItem
{
	GENERATED_BODY()

protected:
	virtual bool Use(AActor* Instigator) override;
	
};
