// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttackAction.h"

#include "SAttributeComponent.h"
#include "SEnemyCharacter.h"
#include "SPlayerCharacter.h"

USAttackAction::USAttackAction()
{
	ActionName = FName(TEXT("AttackAction"));
	CoolDownDuration = 2.0f;
}

void USAttackAction::TakeDamageDelay(USAttributeComponent* attributeComp)
{
	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, [this, attributeComp]() {
		attributeComp->ApplyHealthChange(Damage);
		}, TakeDamgeTimeOffset, false);
}

bool USAttackAction::StartAction(AActor* instigator)
{
	if (!Super::StartAction(instigator))
		return false;

	AutoEnd(instigator);

	auto enemy = Cast<ASEnemyCharacter>(instigator);

	auto attributeComp=enemy->FindComponentByClass<USAttributeComponent>();

	TakeDamageDelay(attributeComp);

	//Play AttackAnimation
	enemy->PlayAnimMontage(AttackAnimMontages[FMath::RandRange(0, AttackAnimMontages.Num()-1)]);

	return true;
}

bool USAttackAction::StopAction(AActor* instigator)
{
	Super::StopAction(instigator);
	return true;
}
