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
    virtual void PostInitializeComponents() override;
    UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void Explode();

public:
    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component")
        TObjectPtr<USphereComponent> CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component")
        TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
        TObjectPtr<UStaticMeshComponent> Mesh;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component")
        TObjectPtr<UParticleSystemComponent> ParticleSystemComponent;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
        TObjectPtr<UParticleSystem> ExplodeParticle;

    bool IsActive;

};
