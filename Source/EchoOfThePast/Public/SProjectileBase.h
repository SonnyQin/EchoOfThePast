// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectileBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS()
class ECHOOFTHEPAST_API ASProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:
    ASProjectileBase();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        TObjectPtr<USphereComponent> CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        TObjectPtr<UStaticMeshComponent> Mesh;

};
