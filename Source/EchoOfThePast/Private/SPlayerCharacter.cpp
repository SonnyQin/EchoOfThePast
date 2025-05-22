// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "SActionComponent.h"
#include "SCollectionComponent.h"
#include "SCollectAction.h"
#include "SUseItemAction.h"
#include "SAttributeComponent.h"
#include "SBackpackComponent.h"
#include "SDialogComponent.h"
#include "Components/TimelineComponent.h"

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

	BackpackComponent = CreateDefaultSubobject<USBackpackComponent>("BackpackComponent");

	PlayerAttributeComponent = CreateDefaultSubobject<USAttributeComponent>("AttributeComponent");

	DialogComponent = CreateDefaultSubobject<USDialogComponent>("DialogComponent");

	SelectObject = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");

	SelectObject->SetupAttachment(CameraComponent);

	DefualtSelectObjectMesh = CreateDefaultSubobject<UStaticMesh>("DefaultSelectObject");

	SwingCurve = CreateDefaultSubobject<UCurveFloat>("SwingCurve");

}

// Called when the game starts or when spawned
void ASPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	ActionComponent->AddAction(this, USCollectAction::StaticClass());

	ActionComponent->AddAction(this, USUseItemAction::StaticClass());

	//SelectObject->SetStaticMesh(DefualtSelectObjectMesh);

	UseTimeline = NewObject<UTimelineComponent>(this, FName("UseTimeline"));
	UseTimeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;
	UseTimeline->SetLooping(false);
	UseTimeline->RegisterComponentWithWorld(GetWorld());

	FOnTimelineFloat ProgressFunction;
	ProgressFunction.BindUFunction(this, FName("HandleObjectSwing"));

	// 绑定 CurveFloat
	if (SwingCurve)
	{
		UseTimeline->AddInterpFloat(SwingCurve, ProgressFunction);
	}
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

	PlayerInputComponent->BindAction("UseItem", IE_Pressed, this, &ASPlayerCharacter::Use);


	//Select Backpack items
	PlayerInputComponent->BindAction("SelectBackpackItem0", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem0);
	PlayerInputComponent->BindAction("SelectBackpackItem1", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem1);
	PlayerInputComponent->BindAction("SelectBackpackItem2", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem2);
	PlayerInputComponent->BindAction("SelectBackpackItem3", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem3);
	PlayerInputComponent->BindAction("SelectBackpackItem4", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem4);
	PlayerInputComponent->BindAction("SelectBackpackItem5", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem5);
	PlayerInputComponent->BindAction("SelectBackpackItem6", IE_Pressed, this, &ASPlayerCharacter::SelectBackpackItem6);

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
	ActionComponent->StartActionByName(this, "UseItemAction");
}

void ASPlayerCharacter::SelectBackpackItem(const int index)
{
	BackpackComponent->SetSelectIndex(index);
}

void ASPlayerCharacter::HandleObjectSwing(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Handle Weapon Swing"));

	FVector SwingOffset = FVector(20.f, -10.f, -15.f); // 向中心斜劈
	FVector NewLocation = FMath::Lerp(SelectObjectRelativeLocation, SelectObjectRelativeLocation + SwingOffset, Value);
	SelectObject->SetRelativeLocation(NewLocation);

	FRotator RotOffset = FRotator(-60.f, 0.f, -20.f); // 向前抬 + 左斜
	FRotator NewRot = FMath::Lerp(SelectObjectRelativeRotation, SelectObjectRelativeRotation + RotOffset, Value);
	SelectObject->SetRelativeRotation(NewRot);

}

