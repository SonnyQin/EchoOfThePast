// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SPhotoItem.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USPhotoItem : public USItem
{
	GENERATED_BODY()

public:
	virtual bool Use(AActor* Instigator) override;
};
