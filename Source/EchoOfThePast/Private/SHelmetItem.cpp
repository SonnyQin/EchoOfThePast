// Fill out your copyright notice in the Description page of Project Settings.


#include "SHelmetItem.h"

#include "SAttributeComponent.h"
#include "SPlayerCharacter.h"

bool USHelmetItem::Use(AActor* Instigator)
{
	if(!Super::Use(Instigator))
		return false;

	auto player = Cast<ASPlayerCharacter>(Instigator);
	auto attributeComp = player->FindComponentByClass<USAttributeComponent>();

	attributeComp->SetHelmetProtection(true);
	//TODO

	return true;
}
