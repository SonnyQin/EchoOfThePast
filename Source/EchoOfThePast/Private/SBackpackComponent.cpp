// Fill out your copyright notice in the Description page of Project Settings.


#include "SBackpackComponent.h"

// Sets default values for this component's properties
USBackpackComponent::USBackpackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	SelectIndex = 0;
	SelectItem = nullptr;
}


// Called when the game starts
void USBackpackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USBackpackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USBackpackComponent::AddItem(TObjectPtr<USItem> Item)
{
	UE_LOG(LogTemp, Warning, TEXT("An Item has been added"));
	if(Backpack.IsEmpty())
	{
		SelectItem = Item;
	}
	Backpack.Emplace(Item);
}

void USBackpackComponent::SetSelectIndex(const int index)
{
	SelectIndex = index;
	if(Backpack.IsValidIndex(index))
	{
		SelectItem = Backpack[index];
	}
}

