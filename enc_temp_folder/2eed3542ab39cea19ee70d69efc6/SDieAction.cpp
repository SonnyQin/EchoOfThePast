// Fill out your copyright notice in the Description page of Project Settings.


#include "SDieAction.h"
#include "SEnemyCharacter.h"

USDieAction::USDieAction()
{
	ActionName = FName(TEXT("DieAction"));
	CoolDownDuration = 0.0f;
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

	// 随机选一个蒙太奇播放
	UAnimMontage* MontageToPlay = DieAnimMontages[FMath::RandRange(0, DieAnimMontages.Num() - 1)];
	float Duration = AI->PlayAnimMontage(MontageToPlay);

	if (Duration <= 0.f)
		return false;

	// 绑定播放结束时的委托
	FOnMontageEnded EndDelegate;
	EndDelegate.BindLambda([AnimInstance, Duration](UAnimMontage* Montage, bool bInterrupted)
		{
			if (!bInterrupted && AnimInstance)
			{
				// 停止播放，定格在最后一帧
				AnimInstance->Montage_SetPosition(Montage, Duration);
				AnimInstance->Montage_SetPlayRate(Montage, 0.0f);
			}
		});

	AnimInstance->Montage_SetEndDelegate(EndDelegate, MontageToPlay);

	return true;
}


bool USDieAction::StopAction(AActor* instigator)
{
	return Super::StopAction(instigator);
}
