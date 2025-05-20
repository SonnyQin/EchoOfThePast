// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "SActionComponent.h"
#include "SCollectionComponent.h"
#include "SCollectAction.h"
#include "SUseItemAction.h"
#include "SAttributeComponent.h"

// Sets default values
ASPlayerCharacter::ASPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->bUsePawnControlRotation = true;

	ActionComponent = CreateDefaultSubobject<USActionComponent>("ActionComponent");

	CollectionComponent = CreateDefaultSubobject<USCollectionComponent>("CollectionComponent");

	PlayerAttributeComponent = CreateDefaultSubobject<USAttributeComponent>("AttributeComponent");
}

// Called when the game starts or when spawned
void ASPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	ActionComponent->AddAction(this, USCollectAction::StaticClass());

	ActionComponent->AddAction(this, USUseItemAction::StaticClass());
}

// Called every frame
void ASPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASPlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction("CollectItem", IE_Pressed, this, &ASPlayerCharacter::CollectItem);

}

void ASPlayerCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}


void ASPlayerCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	// X = Forward (Red)
	// Y = Right (Green)
	// Z = Up (Blue)

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, Value);
}

void ASPlayerCharacter::CollectItem()
{
	ActionComponent->StartActionByName(this, "CollectAction");
}

void ASPlayerCharacter::Use()
{
	ActionComponent->StartActionByName(this, "UseItem");
}

