// Fill out your copyright notice in the Description page of Project Settings.


#include "SSwordItem.h"

USSwordItem::USSwordItem()
{
}

bool USSwordItem::Use(AActor* Instigator)
{
	Super::Use(Instigator);

	return true;
}
