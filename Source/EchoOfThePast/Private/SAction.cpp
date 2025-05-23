// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction.h"


USAction::USAction() :
	bIsActive(false)
{
}

void USAction::Initialize(TObjectPtr<USActionComponent> actionComp)
{
	ActionComponent = actionComp;
}

bool USAction::StartAction(AActor* instigator)
{
	//Avoid Start Action when the Action is executing
	if (bIsActive)
		return false;
	bIsActive = true;
	return true;
}

bool USAction::StopAction(AActor* instigator)
{
	bIsActive = false;
	return true;
}

void USAction::AutoEnd(AActor* Instigator)
{
	GetWorld()->GetTimerManager().SetTimer(CoolDownTimerHandle, [this, Instigator]() {
		this->StopAction(Instigator);
		}, CoolDownDuration, false);
}