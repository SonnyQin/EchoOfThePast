// Fill out your copyright notice in the Description page of Project Settings.


#include "SCollectAction.h"
#include "SAction.h"
#include "SActionComponent.h"
#include "SCollectionComponent.h"
#include "SObjectActor.h"
#include "SPlayerCharacter.h"

USCollectAction::USCollectAction()
{
	ActionName = FName(TEXT("CollectAction"));
}

bool USCollectAction::StartAction(AActor* instigator)
{
	UE_LOG(LogTemp, Warning, TEXT("Start Collect item!!!"));
	auto player = Cast<ASPlayerCharacter>(instigator);
	if(player)
	{
		if(player->CollectionComponent->GetSelected())
		{
			player->CollectionComponent->GetSelectedObject()->OnCollected(ActionComponent->GetOwner());
		}
		
	}

	StopAction(instigator);
	
	return Super::StartAction(instigator);
}

bool USCollectAction::StopAction(AActor* instigator)
{
	return Super::StopAction(instigator);
}
