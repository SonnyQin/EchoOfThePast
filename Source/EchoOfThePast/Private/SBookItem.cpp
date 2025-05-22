// Fill out your copyright notice in the Description page of Project Settings.


#include "SBookItem.h"
#include "SPlayerCharacter.h"
#include "SAttributeComponent.h"

bool USBookItem::Use(AActor* Instigator)
{
	if (!Super::Use(Instigator))
		return false;

	auto player = Cast<ASPlayerCharacter>(Instigator);
	auto attributeComp = player->FindComponentByClass<USAttributeComponent>();

	attributeComp->SetCourageLevel(attributeComp->GetMaxCourageLevel());


	return true;

}
