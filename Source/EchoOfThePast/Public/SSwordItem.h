// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SSwordItem.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USSwordItem : public USItem
{
	GENERATED_BODY()

	USSwordItem();

public:
	virtual bool Use(AActor* Instigator) override;
	
};
