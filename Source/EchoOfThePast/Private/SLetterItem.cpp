// Fill out your copyright notice in the Description page of Project Settings.


#include "SLetterItem.h"

bool USLetterItem::Use(AActor* Instigator)
{
	if (!Super::Use(Instigator))
		return false;

	return true;
}
