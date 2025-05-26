// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttackAction.h"

#include "SAttributeComponent.h"
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

	auto attributeComp=Cast<ASPlayerCharacter>(instigator)->FindComponentByClass<USAttributeComponent>();

	TakeDamageDelay(attributeComp);

	//Play AttackAnimation
	Cast<ASPlayerCharacter>(instigator)->PlayAnimMontage(AttackAnimMontages[FMath::RandRange(0, AttackAnimMontages.Num())]);

	return true;
}

bool USAttackAction::StopAction(AActor* instigator)
{
	Super::StopAction(instigator);
	return true;
}
