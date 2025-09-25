// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Laser.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Spaceshooter_PlayerState.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"


// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	SpriteComponent->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = RootComponent;
	ProjectileMovement->InitialSpeed = 200.f;

	ProjectileMovement->MaxSpeed = 3500.f;
	ProjectileMovement->bRotationFollowsVelocity = false;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	
	float RandomScale = FMath::RandRange(1.f, 2.f);
	float RandomLife = FMath::RandRange(7.0f, 15.0f);
	SetLifeSpan(RandomLife);

	Health = UKismetMathLibrary::RandomIntegerInRange(1, 3);

	SetActorScale3D(FVector(RandomScale));

	UpdateSprite();
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroid::TakeDamageFromLaser()
{
	Health--;

	if (Health <= 0)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC && PC->PlayerState)
		{
			if (ASpaceshooter_PlayerState* PS = Cast<ASpaceshooter_PlayerState>(PC->PlayerState))
			{
				PS->AddScore(100);
			}
		}
		if (ExplosionEffect)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				GetWorld(),
				ExplosionEffect,
				GetActorLocation(),
				GetActorRotation(),
				FVector(0.1f) 
			);
		}
		Destroy();
	}
}

void AAsteroid::UpdateSprite()
{
	switch (Health)
	{
	case 3:
		if (Sprite3) SpriteComponent->SetSprite(Sprite3);
		break;
	case 2:
		if (Sprite2) SpriteComponent->SetSprite(Sprite2);
		break;
	case 1:
		if (Sprite1) SpriteComponent->SetSprite(Sprite1);
		break;
	}
}