// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidSpawner.h"
#include "Asteroid.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "EngineUtils.h"

// Sets default values
AAsteroidSpawner::AAsteroidSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		if (It->ActorHasTag("Spawn_platform"))
		{
			Playground = *It;
			break;
		}
	}
	GetWorldTimerManager().SetTimer(TimerHandle_Spawn, this, &AAsteroidSpawner::SpawnAsteroid, SpawnInterval, true);
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroidSpawner::SpawnAsteroid()
{
	if (!AsteroidClass || !Playground) return;

	FVector Origin;
	FVector BoxExtent;
	Playground->GetActorBounds(false, Origin, BoxExtent);

	FVector SpawnLocation;
	SpawnLocation.X = FMath::RandRange(Origin.X - BoxExtent.X, Origin.X + BoxExtent.X);
	SpawnLocation.Y = FMath::RandRange(Origin.Y - BoxExtent.Y, Origin.Y + BoxExtent.Y);
	SpawnLocation.Z = Origin.Z + BoxExtent.Z + 90.f; 


	float RandomYaw = FMath::RandRange(0.f, 360.f);
	FRotator SpawnRotation = FRotator(0.f, 1.f, 0.f);

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	AAsteroid* Asteroid = GetWorld()->SpawnActor<AAsteroid>(
		AsteroidClass,
		SpawnLocation,
		SpawnRotation,
		SpawnParams
	);
}

