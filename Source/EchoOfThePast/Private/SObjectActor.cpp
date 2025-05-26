// Fill out your copyright notice in the Description page of Project Settings.


#include "SObjectActor.h"
#include "SPlayerCharacter.h"
#include "SBackpackComponent.h"
#include "SItem.h"

// Sets default values
ASObjectActor::ASObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	bIsActive = true;

}

// Called when the game starts or when spawned
void ASObjectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASObjectActor::Tick(float DeltaTime)
{

}

void ASObjectActor::OnSelected(AActor* actor)
{
	UE_LOG(LogTemp, Warning, TEXT("Brighten the Object!!!"));
	//Brighten the Object
	MeshComponent->SetMaterial(0, OutlineMaterial);
}

void ASObjectActor::OnOffSelected(AActor* actor)
{
	UE_LOG(LogTemp, Warning, TEXT("Recovery!!!"));
	//Change to normal color
	MeshComponent->SetMaterial(0, OriginalMaterial);
}

void ASObjectActor::OnCollected(AActor* actor)
{
	if(!bIsActive)
		return;

	bIsActive = false;
	auto player = Cast<ASPlayerCharacter>(actor);
	if (player)
	{
		USBackpackComponent* backpack = Cast<USBackpackComponent>(player->GetComponentByClass(USBackpackComponent::StaticClass()));
		if (backpack && StoreClass)
		{
			// 提前构造 item，避免 lambda 中构造麻烦
			USItem* item = NewObject<USItem>(GetOuter(), StoreClass);

			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, [this, backpack, item, player]() {
				backpack->AddItem(item);
				backpack->SetSelectIndex(backpack->GetSelectIndex());
				this->Destroy();
				}, 1.0f, false);

			UE_LOG(LogTemp, Warning, TEXT("Item will be collected in 1 second..."));
		}
	}
}


FText ASObjectActor::GetItemName() const
{
	return StoreClass.GetDefaultObject()->GetItemName();
}

