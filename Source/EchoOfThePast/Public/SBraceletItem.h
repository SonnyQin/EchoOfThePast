// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SBraceletItem.generated.h"

/**
 * 
 */
UCLASS()
class ECHOOFTHEPAST_API USBraceletItem : public USItem
{
	GENERATED_BODY()


protected:
	virtual bool Use(AActor* Instigator) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		double HealingValue;

public:
	double GetHealingValue() const { return HealingValue; }
	void SetHealingValue(const double healingValue) { HealingValue = healingValue; }

};
