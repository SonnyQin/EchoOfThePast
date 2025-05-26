// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttackAction.h"

#include "SAttributeComponent.h"
#include "SEnemyCharacter.h"
#include "SEnemyController.h"
#include "SPlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SPlayerController.h"

USAttackAction::USAttackAction()
{
	ActionName = FName(TEXT("AttackAction"));
	CoolDownDuration = 2.0f;
}

void USAttackAction::TakeDamageDelay(ASPlayerCharacter* player)
{
	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, [this, player]() {
		auto attributeComp = player->FindComponentByClass<USAttributeComponent>();
		attributeComp->ApplyHealthChange(-Damage);
		Cast<ASPlayerController>(player->GetController())->PerformCameraShake();
		}, TakeDamgeTimeOffset, false);
}

bool USAttackAction::StartAction(AActor* instigator)
{
	if (!Super::StartAction(instigator))
		return false;

	AutoEnd(instigator);

	auto enemy = Cast<ASEnemyCharacter>(instigator);

	auto player = Cast<ASPlayerCharacter>( 
		Cast<ASEnemyController>(enemy->GetController()
		)->GetBlackboardComponent()->GetValueAsObject(TEXT("Player")));

	auto attributeComp= player->FindComponentByClass<USAttributeComponent>();

	TakeDamageDelay(player);

	//Play AttackAnimation
	enemy->PlayAnimMontage(AttackAnimMontages[FMath::RandRange(0, AttackAnimMontages.Num()-1)]);

	return true;
}

bool USAttackAction::StopAction(AActor* instigator)
{
	Super::StopAction(instigator);
	return true;
}
