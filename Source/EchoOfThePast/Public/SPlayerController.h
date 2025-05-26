// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

class UCameraShakeBase;
UCLASS(Blueprintable)
class ECHOOFTHEPAST_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASPlayerController();

public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect")
	TSubclassOf<UCameraShakeBase> CameraShake;
public:
	void PerformCameraShake();
	
};
