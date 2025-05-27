// Fill out your copyright notice in the Description page of Project Settings.


#include "SDieAction.h"
#include "SEnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

USDieAction::USDieAction()
{
	ActionName = FName(TEXT("DieAction"));
	CoolDownDuration = 0.0f;
}

void USDieAction::RagDoll(AActor* Instigator)
{
	ASEnemyCharacter* AI = Cast<ASEnemyCharacter>(Instigator);

	// 切换到物理模拟模式（ragdoll）
	AI->GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
	AI->GetMesh()->SetSimulatePhysics(true);
	AI->GetMesh()->WakeAllRigidBodies();
	AI->GetMesh()->bBlendPhysics = true;

	// 关闭 AI 控制
	AI->DetachFromControllerPendingDestroy();

	// 防止角色悬空
	AI->GetCharacterMovement()->DisableMovement();
	AI->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	FTimerHandle TimerHandle;
	AI->GetWorld()->GetTimerManager().SetTimer(TimerHandle, [AI]() {
		AI->Destroy();
		}, 10, false);
}

bool USDieAction::StartAction(AActor* Instigator)
{
	if (!Super::StartAction(Instigator))
		return false;

	AutoEnd(Instigator);

	ASEnemyCharacter* AI = Cast<ASEnemyCharacter>(Instigator);
	if (!AI || DieAnimMontages.Num() == 0)
		return false;

	UAnimInstance* AnimInstance = AI->GetMesh()->GetAnimInstance();
	if (!AnimInstance)
		return false;

	RagDoll(Instigator);

	//// 随机播放一个死亡动画
	//UAnimMontage* MontageToPlay = DieAnimMontages[FMath::RandRange(0, DieAnimMontages.Num() - 1)];
	//float Duration = AI->PlayAnimMontage(MontageToPlay);

	//if (Duration <= 0.f)
	//	return false;

	// 动画播放结束后进入 ragdoll
	//FOnMontageEnded EndDelegate;
	//EndDelegate.BindLambda([AI](UAnimMontage* Montage, bool bInterrupted)
	//	{
	//		if (!bInterrupted && AI && AI->GetMesh())
	//		{
	//			
	//		}
	//	});

	//AnimInstance->Montage_SetEndDelegate(EndDelegate, MontageToPlay);

	return true;
}



bool USDieAction::StopAction(AActor* instigator)
{
	return Super::StopAction(instigator);
}
