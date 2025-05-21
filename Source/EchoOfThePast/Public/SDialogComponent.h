// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SDialogComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECHOOFTHEPAST_API USDialogComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USDialogComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialog")
		FText DialogText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialog")
		FText ItemText;

public:
	UFUNCTION(BlueprintCallable)
	void SetDialogText(const FText text) { DialogText = text; }
	UFUNCTION(BlueprintCallable)
	FText GetDialogText() const { return DialogText; }
	UFUNCTION(BlueprintCallable)
	void SetDialogDurableText(const FText text, const float time);

	UFUNCTION(BlueprintCallable)
		void SetItemText(const FText text) { ItemText = text; }
	UFUNCTION(BlueprintCallable)
		FText GetItemText() const { return ItemText; }
		
};
