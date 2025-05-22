// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Health = 100;
	MaxHealth = 100;
	CourageLevel = 0;
	MaxCourageLevel = 100;
	bInvincibility = false;
	bNearDeathProtection = false;
	bHelmetProtection = false;
}


// Called when the game starts
void USAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Health = MaxHealth;
	CourageLevel = MaxHealth;
}


// Called every frame
void USAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USAttributeComponent::ApplyHealthChange(double delta)
{
	if(bInvincibility&&delta<0)
		return;
	if(Health+delta<=0&&bNearDeathProtection)
	{
		bNearDeathProtection = false;
		return;
	}

	Health += delta;
	if (Health > MaxHealth)
		Health = MaxHealth;
	if (Health < 0)
		Health = 0;
}

void USAttributeComponent::ApplyTerrorChange(double delta)
{
	CourageLevel += delta;
	if (CourageLevel > MaxCourageLevel)
		CourageLevel = MaxCourageLevel;
	if (CourageLevel < 0)
		CourageLevel = 0;
}

