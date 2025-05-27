// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ECHOOFTHEPAST_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USAttributeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void ApplyHealthChange(double delta);
	void ApplyCourageChange(double delta);

	void Die();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		double Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
		double CourageLevel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly , Category = "Attributes")
		double MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
		double MaxCourageLevel;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		bool bInvincibility;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		bool bNearDeathProtection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		bool bHelmetProtection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		bool bIsDead;
public:
	UFUNCTION(BlueprintCallable)
		double GetHealth() const { return Health; }
	UFUNCTION(BlueprintCallable)
		double GetCourageLevel() const { return CourageLevel; }
	UFUNCTION(BlueprintCallable)
		double GetMaxHealth() const { return MaxHealth; }
	UFUNCTION(BlueprintCallable)
		double GetMaxCourageLevel() const { return MaxCourageLevel; }

	void SetHealth(const double health) { Health = health; }

	void SetCourageLevel(const double courageLevel) { CourageLevel = courageLevel; }

	bool GetInvincibility() const { return bInvincibility; }
	void SetInvincibility(const bool invincibility) { bInvincibility = invincibility; }

	bool GetNearDeathProtection() const { return bNearDeathProtection; }
	void SetNearDeathProtection(const bool nearDeathProtection) { bNearDeathProtection = nearDeathProtection; }

	bool GetHelmetProtection() const { return bNearDeathProtection; }
	void SetHelmetProtection(const bool helmetProtection) { bNearDeathProtection = helmetProtection; }

	UFUNCTION(BlueprintCallable)
	bool GetIsDead() const { return bIsDead; }

	UFUNCTION(BlueprintCallable)
	void SetIsDead(const bool active) { bIsDead = active; }
};
