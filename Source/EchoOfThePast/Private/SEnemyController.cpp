// Fill out your copyright notice in the Description page of Project Settings.


#include "SEnemyController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "EchoOfThePast/EchoOfThePastGameModeBase.h"

ASEnemyController::ASEnemyController()
{
}

void ASEnemyController::BeginPlay()
{
	Super::BeginPlay();

	if (ensureMsgf(BehaviorTree, TEXT("Behavior Tree is nullptr! Please assign BehaviorTree in your AI Controller.")))
	{
		RunBehaviorTree(BehaviorTree);
	}
	
	TargetPlayer = Cast<AEchoOfThePastGameModeBase>(GetWorld()->GetAuthGameMode())->GetPlayerCharacter();
}

void ASEnemyController::StopBehaviorTree()
{
	UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(BrainComponent);
	BTComp->StopTree(EBTStopMode::Safe);
}
