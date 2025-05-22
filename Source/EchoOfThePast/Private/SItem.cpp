// Fill out your copyright notice in the Description page of Project Settings.


#include "SItem.h"

#include "SAttributeComponent.h"
#include "SPlayerCharacter.h"

USItem::USItem()
{
	bIsCooling = false;
}

bool USItem::Use(AActor* Instigator)
{
	if (bIsCooling&&StartTime + CoolDown <= GetWorld()->GetTimeSeconds())
	{
		return false;
	}

	bIsCooling = true;
	StartTime = GetWorld()->GetTimeSeconds();
	auto player = Cast<ASPlayerCharacter>(Instigator);
	auto attributeComp = player->FindComponentByClass<USAttributeComponent>();

	auto courage = attributeComp->GetCourageLevel();

	if (courage - CourageCost < 0)
		return false;

	return true;

}
