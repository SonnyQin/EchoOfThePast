// Fill out your copyright notice in the Description page of Project Settings.


#include "SDieAction.h"
#include "SEnemyCharacter.h"

USDieAction::USDieAction()
{
	ActionName = FName(TEXT("DieAction"));
	CoolDownDuration = 0.0f;
}

bool USDieAction::StartAction(AActor* instigator)
{
	if (!Super::StartAction(instigator))
		return false;

	AutoEnd(instigator);

	auto AI = Cast<ASEnemyCharacter>(instigator);
	AI->PlayAnimMontage(DieAnimMontages[FMath::RandRange(0, DieAnimMontages.Num()-1)]);

	return true;
}

bool USDieAction::StopAction(AActor* instigator)
{
	return Super::StopAction(instigator);
}
