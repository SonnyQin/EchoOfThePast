// Fill out your copyright notice in the Description page of Project Settings.


#include "SActionComponent.h"
#include "SAction.h"

// Sets default values for this component's properties
USActionComponent::USActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USActionComponent::AddAction(AActor* Instigator, TSubclassOf<USAction> ActionClass)
{
	if (!ensure(ActionClass))
	{
		return;
	}

	USAction* NewAction = NewObject<USAction>(GetOwner(), ActionClass);
	if (ensure(NewAction))
	{
		NewAction->Initialize(this);

		Actions.Add(NewAction);
	}
}

void USActionComponent::RemoveAction(USAction* ActionToRemove)
{
	for(auto action:Actions)
	{
		if(action==ActionToRemove)
		{
			Actions.Remove(action);
		}
	}
}

USAction* USActionComponent::GetAction(TSubclassOf<USAction> ActionClass) const
{
	for (USAction* Action : Actions)
	{
		if (Action && Action->IsA(ActionClass)) // 判断是否是指定的类型
		{
			return Action;
		}
	}

	return nullptr; // 如果没有找到，返回空指针
}


bool USActionComponent::StartActionByName(AActor* instigator, FName actionName)
{
	for(auto action:Actions)
	{
		if(action->GetActionName()==actionName)
		{
			return action->StartAction(instigator);
		}
	}
	return false;
}

bool USActionComponent::StopActionByName(AActor* instigator, FName actionName)
{
	for (auto action : Actions)
	{
		if (action->GetActionName() == actionName)
		{
			return action->StopAction(instigator);
		}
	}
	return false;
}

