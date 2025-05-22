// Fill out your copyright notice in the Description page of Project Settings.


#include "SPhotoItem.h"

bool USPhotoItem::Use(AActor* Instigator)
{
	if (!Super::Use(Instigator))
		return false;
	return true;
}
