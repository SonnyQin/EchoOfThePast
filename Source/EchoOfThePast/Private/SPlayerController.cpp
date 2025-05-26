// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerController.h"

ASPlayerController::ASPlayerController()
{

}

void ASPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ASPlayerController::PerformCameraShake()
{
	if(CameraShake)
		ClientStartCameraShake(CameraShake);
}
