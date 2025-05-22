// Fill out your copyright notice in the Description page of Project Settings.


#include "SCoinItem.h"

#include "SAttributeComponent.h"
#include "SPlayerCharacter.h"

bool USCoinItem::Use(AActor* Instigator)
{
	if (!Super::Use(Instigator))
		return false;

	auto player = Cast<ASPlayerCharacter>(Instigator);
	auto attributeComp = player->FindComponentByClass<USAttributeComponent>();

	attributeComp->SetNearDeathProtection(true);


	return true;
}
