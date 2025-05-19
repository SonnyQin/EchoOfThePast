// Fill out your copyright notice in the Description page of Project Settings.


#include "SObjectActor.h"
#include "SPlayerCharacter.h"

// Sets default values
ASObjectActor::ASObjectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

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
	auto player = Cast<ASPlayerCharacter>(actor);
	if(player)
	{
		FTimerHandle timerHandle;

		GetWorld()->GetTimerManager().SetTimer(timerHandle, [this]() {
			this->Destroy();
			}, 1.0f, false);
		UE_LOG(LogTemp, Warning, TEXT("Item being collected!!!"));
		//TODO Add to player's backpack
	}
}

