// Fill out your copyright notice in the Description page of Project Settings.


#include "SBTTask_PlayAnimation.h"
#include "AIController.h"
#include "GameFramework/Character.h"

USBTTask_PlayAnimation::USBTTask_PlayAnimation()
{
	AnimMontage = CreateDefaultSubobject<UAnimMontage>("AnimMontage");
	bIsPlaying = false;
}

EBTNodeResult::Type USBTTask_PlayAnimation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon) return EBTNodeResult::Failed;

	ACharacter* Char = Cast<ACharacter>(AICon->GetPawn());
	if (!Char) return EBTNodeResult::Failed;

	Char->PlayAnimMontage(AnimMontage);
	bNotifyTick = true; // ¿ªÆô Tick
	bIsPlaying = true;
	return EBTNodeResult::InProgress;
}

void USBTTask_PlayAnimation::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon) return;
	if (!bIsPlaying) return;
	ACharacter* Char = Cast<ACharacter>(AICon->GetPawn());
	if (!Char->GetMesh()->GetAnimInstance()->Montage_IsPlaying(AnimMontage))
	{
		bIsPlaying = false;
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}

}