// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SAction.generated.h"

class USActionComponent;

UCLASS()
class ECHOOFTHEPAST_API USAction : public UObject
{
	
	GENERATED_BODY()

	USAction();

public:
	void Initialize(TObjectPtr<USActionComponent> actionComp);

	UFUNCTION(BlueprintCallable, Category = "Actions")
		virtual bool StartAction(AActor* instigator);
	UFUNCTION(BlueprintCallable, Category = "Actions")
		virtual bool StopAction(AActor* instigator);

protected:
	UPROPERTY()
	TObjectPtr<USActionComponent> ActionComponent;

	UPROPERTY(EditAnywhere, Category="Actions")
	FName ActionName;

public:
	FName GetActionName() const { return ActionName; }
};
