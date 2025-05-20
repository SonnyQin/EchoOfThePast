// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECHOOFTHEPAST_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USAttributeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void ApplyHealthChange(double delta);
	void ApplyTerrorChange(double delta);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		double Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		double TerrorLevel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly , Category = "Attributes")
		double MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
		double MaxTerrorLevel;
public:
	UFUNCTION(BlueprintCallable)
		double GetHealth() const { return Health; }
	UFUNCTION(BlueprintCallable)
		double GetTerrorLevel() const { return TerrorLevel; }
	UFUNCTION(BlueprintCallable)
		double GetMaxHealth() const { return MaxHealth; }
	UFUNCTION(BlueprintCallable)
		double GetMaxTerrorLevel() const { return MaxTerrorLevel; }
};
