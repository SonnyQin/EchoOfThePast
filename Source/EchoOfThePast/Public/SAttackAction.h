// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SAttackAction.generated.h"

class USAttributeComponent;
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USAttackAction : public USAction
{
	GENERATED_BODY()

public:
	USAttackAction();

protected:

	void TakeDamageDelay(USAttributeComponent* attributeComp);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
		double AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
		double Damage;
	//Unable to take damage immediately, need to wait for an offset for the animation to perform
	//then take the damage,
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
		double TakeDamgeTimeOffset;

	//Make Sure coolding down time is longger than AnimMontage time
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
		TArray<TObjectPtr<UAnimMontage>>  AttackAnimMontages;

protected:
		virtual bool StartAction(AActor* instigator) override;
		virtual bool StopAction(AActor* instigator) override;

};
