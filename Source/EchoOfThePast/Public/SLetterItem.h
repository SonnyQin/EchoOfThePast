// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SLetterItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USLetterItem : public USItem
{
	GENERATED_BODY()

protected:
	virtual bool Use(AActor* Instigator) override;
	
};
