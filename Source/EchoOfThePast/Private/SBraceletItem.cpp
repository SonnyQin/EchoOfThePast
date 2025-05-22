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

	attributeComp->ApplyHealthChange(HealingValue);

	return true;

}
