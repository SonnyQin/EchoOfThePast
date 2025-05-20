// Fill out your copyright notice in the Description page of Project Settings.


#include "SUseItemAction.h"

#include "SBackpackComponent.h"
#include "SItem.h"
#include "SPlayerCharacter.h"

USUseItemAction::USUseItemAction()
{
	ActionName = FName(TEXT("UseItemAction"));
}

bool USUseItemAction::StartAction(AActor* instigator)
{
	Super::StartAction(instigator);
	auto player = Cast<ASPlayerCharacter>(instigator);
	auto backpackComp = Cast<USBackpackComponent>(player->GetComponentByClass(USBackpackComponent::StaticClass()));

	if(backpackComp)
	{
		if(backpackComp->GetSelectItem())
		{
			backpackComp->GetSelectItem()->Use(instigator);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	StopAction(instigator);

	return true;
}

bool USUseItemAction::StopAction(AActor* instigator)
{
	Super::StopAction(instigator);
	return true;
}
