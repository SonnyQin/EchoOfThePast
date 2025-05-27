// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.h"
#include "SJarItem.generated.h"

class ASProjectileBase;
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USJarItem : public USItem
{
	GENERATED_BODY()

protected:
	virtual bool Use(AActor* Instigator) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
		TSubclassOf<ASProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TObjectPtr<USoundBase> CastingSound;
	
};
