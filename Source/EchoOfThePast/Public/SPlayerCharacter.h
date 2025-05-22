// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SPlayerCharacter.generated.h"

#define DEFINE_SELECT_ITEM(N) void SelectBackpackItem##N() { SelectBackpackItem(N); }

class UCameraComponent;
class USActionComponent;
class USCollectionComponent;
class USBackpackComponent;
class USAttributeComponent;
class USDialogComponent;
class UTimelineComponent;

UCLASS()
class ECHOOFTHEPAST_API ASPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Component")
	TObjectPtr<USActionComponent> ActionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	TObjectPtr<USCollectionComponent> CollectionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
		TObjectPtr<USBackpackComponent> BackpackComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component")
	TObjectPtr<USAttributeComponent> PlayerAttributeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Component")
		TObjectPtr<USDialogComponent> DialogComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
		TObjectPtr<UStaticMeshComponent> SelectObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Component")
		TObjectPtr<UStaticMesh> DefualtSelectObjectMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
		TObjectPtr<UTimelineComponent> UseTimeline;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
		TObjectPtr<UCurveFloat> SwingCurve;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Data")
		FVector SelectObjectRelativeLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Data")
		FRotator SelectObjectRelativeRotation;

protected:
	//Actions
	UFUNCTION(BlueprintCallable)
		void CollectItem();
	UFUNCTION(BlueprintCallable)
		void Use();
	UFUNCTION(BlueprintCallable)
		void SelectBackpackItem(const int index);

	DEFINE_SELECT_ITEM(0)
	DEFINE_SELECT_ITEM(1)
	DEFINE_SELECT_ITEM(2)
	DEFINE_SELECT_ITEM(3)
	DEFINE_SELECT_ITEM(4)
	DEFINE_SELECT_ITEM(5)
	DEFINE_SELECT_ITEM(6)

	UFUNCTION()
	void HandleObjectSwing(float Value);

public:
	UFUNCTION()
	UTimelineComponent* GetUseTimeline() const { return UseTimeline; }

	UFUNCTION()
	FVector GetSelectObjectRelativeLocation() const { return SelectObjectRelativeLocation; }

	UFUNCTION()
	void SetSelectObjectRelativeLocation(const FVector location) { SelectObjectRelativeLocation = location; }

	UFUNCTION()
	FRotator GetSelectObjectRelativeRotation() const { return SelectObjectRelativeRotation; }

	UFUNCTION()
	void SetSelectObjectRelativeRotation(const FRotator rotation) { SelectObjectRelativeRotation = rotation; }

	UFUNCTION()
	UStaticMeshComponent* GetSelectObject() const { return SelectObject;	 }

	UFUNCTION()
	void SetSelectObjectMesh(UStaticMesh* selectMesh) { SelectObject->SetStaticMesh(selectMesh); }

	UFUNCTION()
	UStaticMesh* GetDefualtSelectObjectMesh() const { return DefualtSelectObjectMesh; }

};
