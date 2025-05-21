// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttackAction.h"

USAttackAction::USAttackAction()
{
}

bool USAttackAction::StartAction(AActor* instigator)
{
	return Super::StartAction(instigator);
}

bool USAttackAction::StopAction(AActor* instigator)
{
	return Super::StopAction(instigator);
}
