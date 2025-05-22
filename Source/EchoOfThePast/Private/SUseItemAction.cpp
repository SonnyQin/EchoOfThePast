// Fill out your copyright notice in the Description page of Project Settings.


#include "SUseItemAction.h"

#include "SBackpackComponent.h"
#include "SItem.h"
#include "SPlayerCharacter.h"
#include "Components/TimelineComponent.h"

USUseItemAction::USUseItemAction()
{
	ActionName = FName(TEXT("UseItemAction"));
	Duration = 0.4;
}

bool USUseItemAction::StartAction(AActor* instigator)
{

	if (bIsActive)
		return false;

	Super::StartAction(instigator);

	AutoEnd(instigator);

	auto player = Cast<ASPlayerCharacter>(instigator);

	player->SetSelectObjectRelativeLocation(player->GetSelectObject()->GetRelativeLocation());
	player->SetSelectObjectRelativeRotation(player->GetSelectObject()->GetRelativeRotation());

	auto useTimeline = player->GetUseTimeline();
		if (useTimeline)
		{
			useTimeline->PlayFromStart();
		}

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

	return true;
}

bool USUseItemAction::StopAction(AActor* instigator)
{
	Super::StopAction(instigator);
	return true;
}
