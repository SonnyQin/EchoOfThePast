// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTTask_Attack.h"
#include "AIController.h"

EBTNodeResult::Type USBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon) return EBTNodeResult::Failed;

	APawn* AIPawn = AICon->GetPawn();
	if (!AIPawn) return EBTNodeResult::Failed;


	return EBTNodeResult::Succeeded;
}
