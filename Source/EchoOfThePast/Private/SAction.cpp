// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction.h"


USAction::USAction()
{
}

void USAction::Initialize(TObjectPtr<USActionComponent> actionComp)
{
	ActionComponent = actionComp;
}

bool USAction::StartAction(AActor* instigator)
{
	return true;
}

bool USAction::StopAction(AActor* instigator)
{
	return true;
}
