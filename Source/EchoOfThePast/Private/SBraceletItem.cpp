// Fill out your copyright notice in the Description page of Project Settings.


#include "SBraceletItem.h"

#include "SAttributeComponent.h"
#include "SPlayerCharacter.h"

bool USBraceletItem::Use(AActor* Instigator)
{
	if (!Super::Use(Instigator))
		return false;

	auto player = Cast<ASPlayerCharacter>(Instigator);
	auto attributeComp = player->FindComponentByClass<USAttributeComponent>();

	if(attributeComp->GetHealth()==attributeComp->GetMaxHealth())
	{
		//Restore the cost if the health is full
		attributeComp->ApplyCourageChange(CourageCost);
		return true;
	}

	attributeComp->ApplyHealthChange(HealingValue);

	return true;

}
