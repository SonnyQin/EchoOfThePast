// Fill out your copyright notice in the Description page of Project Settings.


#include "SEnemyCharacter.h"

#include "SActionComponent.h"
#include "SAttributeComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EchoOfThePast/EchoOfThePastGameModeBase.h"
#include "SPlayerCharacter.h"
#include "SAction.h"

// Sets default values
ASEnemyCharacter::ASEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttributeComponent = CreateDefaultSubobject<USAttributeComponent>("AttributeComponent");
	ActionComponent = CreateDefaultSubobject<USActionComponent>("ActionComponent");
	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");
	PawnSensingComponent->bSeePawns = true;

}

// Called when the game starts or when spawned
void ASEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Adding all blueprint actions to here
	for (auto iter : ExtraActions)
	{
		ActionComponent->AddAction(this, iter->GetClass());
	}


	auto blackboard = Cast<AAIController>(GetController())->GetBlackboardComponent();
	blackboard->SetValueAsObject(FName(TEXT("Player")), Cast<AEchoOfThePastGameModeBase>(GetWorld()->GetAuthGameMode())->GetPlayerCharacter());

	blackboard->SetValueAsBool(FName(TEXT("bCanSeePlayer")), false);
	blackboard->SetValueAsBool(FName(TEXT("bCanAttackPlayer")), false);

	PawnSensingComponent->OnSeePawn.AddDynamic(this, &ASEnemyCharacter::OnSeenPawn);
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

void ASEnemyCharacter::OnSeenPawn(APawn* pawn)
{
	if(pawn->IsA(ASPlayerCharacter::StaticClass()))
	{
		auto blackboard = Cast<AAIController>(GetController())->GetBlackboardComponent();
		blackboard->SetValueAsBool(FName(TEXT("bCanSeePlayer")), true);
	}
}

void ASEnemyCharacter::Attack()
{
	ActionComponent->StartActionByName(this, "AttackAction");
}

void ASEnemyCharacter::Die()
{
	ActionComponent->StartActionByName(this, "DieAction");
}

