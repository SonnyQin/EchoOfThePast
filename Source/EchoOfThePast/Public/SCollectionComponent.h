// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SCollectionComponent.generated.h"


class ASObjectActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECHOOFTHEPAST_API USCollectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USCollectionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	bool PerformRayCast();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collection")
		double TraceDistance;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collection")
		bool bIsSelected;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collection")
		TObjectPtr<ASObjectActor> SelectedObject;
public:
	double GetTraceDistance() const { return TraceDistance; }
	double GetSelected() const { return bIsSelected; }
	TObjectPtr<ASObjectActor> GetSelectedObject() const { return SelectedObject; }
};
