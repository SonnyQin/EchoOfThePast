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
	bIsActive = true;
	return true;
}

bool USAction::StopAction(AActor* instigator)
{
	bIsActive = false;
	return true;
}
