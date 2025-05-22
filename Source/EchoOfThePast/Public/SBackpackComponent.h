// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SBackpackComponent.generated.h"


class USItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECHOOFTHEPAST_API USBackpackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USBackpackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
public:
	void AddItem(TObjectPtr<USItem> Item);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Backpack")
	TArray<TObjectPtr<USItem>> Backpack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Backpack")
		int BackpackSize;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Backpack")
		TObjectPtr<USItem> SelectItem;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Backpack")
		int SelectIndex;
public:
	UFUNCTION(BlueprintCallable)
	USItem* GetSelectItem() const { return SelectItem; }

	UFUNCTION(BlueprintCallable)
	int GetSelectIndex() const { return SelectIndex; }

	UFUNCTION(BlueprintCallable)
	void SetSelectIndex(const int index);
		
};
