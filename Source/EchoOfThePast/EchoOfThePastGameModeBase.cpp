// Copyright Epic Games, Inc. All Rights Reserved.


#include "EchoOfThePastGameModeBase.h"
#include "SPlayerCharacter.h"

AEchoOfThePastGameModeBase::AEchoOfThePastGameModeBase()
{

}

ASPlayerCharacter* AEchoOfThePastGameModeBase::GetPlayerCharacter()
{
	return Cast<ASPlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
