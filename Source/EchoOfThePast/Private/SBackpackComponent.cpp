// Fill out your copyright notice in the Description page of Project Settings.


#include "SBackpackComponent.h"

#include "SItem.h"
#include "SPlayerCharacter.h"

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
	auto player = Cast<ASPlayerCharacter>(GetOwner());

	SelectIndex = index;
	if(Backpack.IsValidIndex(index))
	{
		SelectItem = Backpack[index];
		//TODO
		player->SetSelectObjectMesh(SelectItem->GetStaticMesh());

		//Adjust the Select Object's mesh
		auto loc = player->GetInitialSelectObjectLocation() + SelectItem->GetHoldLocationOffset();
		auto rot = player->GetInitialSelectObjectRotation() + SelectItem->GetHoldRotationOffset();
		player->SetSelectObjectRelativeLocation(loc);
		player->SetSelectObjectRelativeRotation(rot);
		player->GetSelectObject()->SetRelativeScale3D(player->GetInitialSelectObjectScale() + SelectItem->GetHoldScaleOffset());
		player->GetSelectObject()->SetRelativeLocation(loc);
		player->GetSelectObject()->SetRelativeRotation(rot);
	}
	else
	{
		SelectItem = nullptr;
		player->SetSelectObjectMesh(player->GetDefualtSelectObjectMesh());

		//Change back to default
		auto loc = player->GetInitialSelectObjectLocation();
		auto rot = player->GetInitialSelectObjectRotation();
		player->SetSelectObjectRelativeLocation(player->GetInitialSelectObjectLocation());
		player->SetSelectObjectRelativeRotation(player->GetInitialSelectObjectRotation());
		player->GetSelectObject()->SetRelativeScale3D(player->GetInitialSelectObjectScale());
		player->GetSelectObject()->SetRelativeLocation(loc);
		player->GetSelectObject()->SetRelativeRotation(rot);
	}
}

