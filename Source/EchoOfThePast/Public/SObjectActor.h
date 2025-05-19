// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SObjectActor.generated.h"


//TODO Add object types
//UENUM()
//enum EObjectType
//{
//};

//Use for objects that are able to be collected

UCLASS(Blueprintable)
class ECHOOFTHEPAST_API ASObjectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASObjectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void OnSelected(AActor* actor);

	UFUNCTION(BlueprintCallable)
	virtual void OnOffSelected(AActor* actor);

	UFUNCTION(BlueprintCallable)
	virtual void OnCollected(AActor* actor);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
		TObjectPtr<UMaterial> OriginalMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mesh")
		TObjectPtr<UMaterial> OutlineMaterial;

};
