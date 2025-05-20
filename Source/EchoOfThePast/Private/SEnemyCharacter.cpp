// Fill out your copyright notice in the Description page of Project Settings.


#include "SEnemyCharacter.h"

#include "SActionComponent.h"
#include "SAttributeComponent.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
ASEnemyCharacter::ASEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttributeComponent = CreateDefaultSubobject<USAttributeComponent>("AttributeComponent");
	ActionComponent = CreateDefaultSubobject<USActionComponent>("ActionComponent");
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");

}

// Called when the game starts or when spawned
void ASEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

