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
public:
	UFUNCTION(BlueprintCallable)
		virtual void Use(AActor* Instigator);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
		FText ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	TObjectPtr<UTexture2D> Texture;

public:
	FText GetItemName() const { return ItemName; }

};
