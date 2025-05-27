// Fill out your copyright notice in the Description page of Project Settings.


#include "SProjectileBase.h"

#include "SActionComponent.h"
#include "SAttributeComponent.h"
#include "SEnemyCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASProjectileBase::ASProjectileBase()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block); // 或其他你想拦的通道
	CollisionComponent->SetNotifyRigidBodyCollision(true); // ✅ 这一行必须有，才能触发 OnComponentHit

    RootComponent = CollisionComponent;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 1000.f;
    ProjectileMovement->MaxSpeed = 1000.f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;

    ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
    ParticleSystemComponent->SetupAttachment(RootComponent);

	IsActive = true;
}


// Called when the game starts or when spawned
void ASProjectileBase::BeginPlay()
{
	Super::BeginPlay();

    ParticleSystemComponent->bAutoActivate = true;
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASProjectileBase::OnActorOverlap);

}

void ASProjectileBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

void ASProjectileBase::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsActive)
		return;
	Explode();
	IsActive = false;

	if (!OtherActor || OtherActor == this)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit invalid actor or self."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Projectile hit actor: %s"), *OtherActor->GetName());

	if (ASEnemyCharacter* Enemy = Cast<ASEnemyCharacter>(OtherActor))
	{
		if (USAttributeComponent* AttributeComp = Enemy->FindComponentByClass<USAttributeComponent>())
		{
			AttributeComp->ApplyHealthChange(-50.0f);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy has no AttributeComponent!"));
		}

		Enemy->FindComponentByClass<USActionComponent>()->StartActionByName(Enemy, "HurtAction");
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit actor is not an enemy."));
	}

}

void ASProjectileBase::Explode()
{
	ParticleSystemComponent->SetTemplate(ExplodeParticle);

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {
		this->Destroy();
		}, 5.0f, false);
}

// Called every frame
void ASProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

