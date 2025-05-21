// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SEnemyCharacter.generated.h"

class USAttributeComponent;
class USActionComponent;
class UPawnSensingComponent;

UCLASS()
class ECHOOFTHEPAST_API ASEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UFUNCTION()
	void OnSeenPawn(APawn* pawn);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Components")
	TObjectPtr<USAttributeComponent> AttributeComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USActionComponent> ActionComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UPawnSensingComponent> PawnSensingComponent;
};
