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

public:
	USAction();

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

	UPROPERTY(EditAnywhere, Category = "Actions")
	double CoolDownDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actions")
		FTimerHandle CoolDownTimerHandle;

public:
	UFUNCTION(BlueprintCallable)
	FName GetActionName() const { return ActionName; }

	UFUNCTION(BlueprintCallable)
		void AutoEnd(AActor* Instigator);

protected:
	bool bIsActive;
};
