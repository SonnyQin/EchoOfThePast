// Fill out your copyright notice in the Description page of Project Settings.


#include "SItem.h"

#include "SAttributeComponent.h"
#include "SPlayerCharacter.h"

USItem::USItem()
{

}

bool USItem::Use(AActor* Instigator)
{
	auto player = Cast<ASPlayerCharacter>(Instigator);
	auto attributeComp = player->FindComponentByClass<USAttributeComponent>();

	auto courage = attributeComp->GetCourageLevel();

	if (courage - CourageCost < 0)
		return false;

	return true;

}
