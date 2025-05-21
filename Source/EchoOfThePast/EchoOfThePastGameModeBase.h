// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EchoOfThePastGameModeBase.generated.h"

class ASPlayerCharacter;
UCLASS()
class ECHOOFTHEPAST_API AEchoOfThePastGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEchoOfThePastGameModeBase();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerAttributes")
	FString UserName;

public:
	ASPlayerCharacter* GetPlayerCharacter();
};
