// Fill out your copyright notice in the Description page of Project Settings.


#include "SHurtAction.h"

#include "SEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

USHurtAction::USHurtAction()
{
	ActionName = FName(TEXT("HurtAction"));
	CoolDownDuration = 0.0f;
}

bool USHurtAction::StartAction(AActor* instigator)
{
	if (!Super::StartAction(instigator))
		return false;

	auto AI = Cast<ASEnemyCharacter>(instigator);

	AI->PlayAnimMontage(HurtAnimMontages[FMath::RandRange(0, HurtAnimMontages.Num() - 1)]);

	StopAction(instigator);

	return true;
}

bool USHurtAction::StopAction(AActor* instigator)
{
	return Super::StopAction(instigator);
}
