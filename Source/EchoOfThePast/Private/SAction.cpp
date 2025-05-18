// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction.h"

USAction::USAction(TObjectPtr<USActionComponent> owner)
{
	ActionComponent = owner;
}

void USAction::Initialize()
{
}

bool USAction::StartAction(AActor* instigator)
{
}

bool USAction::StopAction(AActor* instigator)
{
}
