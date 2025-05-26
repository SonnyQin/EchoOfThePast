// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SItem.generated.h"



UCLASS(Blueprintable)
class ECHOOFTHEPAST_API USItem : public UObject
{
	GENERATED_BODY()

public:
	USItem();
public:
	UFUNCTION(BlueprintCallable)
		virtual bool Use(AActor* Instigator);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
		FText ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	TObjectPtr<UTexture2D> Texture;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
		TObjectPtr<UStaticMesh> StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
		double CoolDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
		double CourageCost;

	//以 defualt staticMesh Object 为基准
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		FVector HoldLocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		FRotator HoldRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		FVector HoldScaleOffset;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
		double StartTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
		bool bIsCooling;

public:
	UFUNCTION(BlueprintCallable)
	FText GetItemName() const { return ItemName; }
	UFUNCTION(BlueprintCallable)
	UTexture2D* GetTexture() const { return Texture; }
	UFUNCTION(BlueprintCallable)
		UStaticMesh* GetStaticMesh() const { return StaticMesh; }

	double GetCoolDownTime() const { return CoolDown; }

	double GetStartTime() const { return StartTime; }

	FVector GetHoldLocationOffset() const { return HoldLocationOffset; }
	FRotator GetHoldRotationOffset() const { return HoldRotationOffset; }
	FVector GetHoldScaleOffset() const { return HoldScaleOffset; }

};
