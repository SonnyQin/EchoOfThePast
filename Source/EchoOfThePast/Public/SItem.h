// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.generated.h"



UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USItem : public UObject
{
	GENERATED_BODY()

public:
	USItem();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	TObjectPtr<UTexture2D> Texture;
};
