// Fill out your copyright notice in the Description page of Project Settings.


#include "SJarItem.h"

#include "SPlayerCharacter.h"
#include "SProjectileBase.h"
#include "Camera/CameraComponent.h"

bool USJarItem::Use(AActor* Instigator)
{
	if (!Super::Use(Instigator))
		return false;

	ASPlayerCharacter* Player = Cast<ASPlayerCharacter>(Instigator);
	if (!Player) return false;

	UCameraComponent* Camera = Player->FindComponentByClass<UCameraComponent>();
	if (!Camera) return false;

	FVector SpawnLocation = Camera->GetComponentLocation();
	FRotator SpawnRotation = Camera->GetComponentRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Player;
	SpawnParams.Owner = Instigator;

	GetWorld()->SpawnActor<ASProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

	return true;
}
