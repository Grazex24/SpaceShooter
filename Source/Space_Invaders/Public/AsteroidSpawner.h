// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidSpawner.generated.h"

UCLASS()
class SPACE_INVADERS_API AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidSpawner();

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AAsteroid> AsteroidClass;

	// La plateforme sur laquelle spawner
	UPROPERTY(EditAnywhere, Category = "Spawn")
	AActor* Playground;

	// Timer entre chaque spawn
	UPROPERTY(EditAnywhere, Category = "Spawn")
	float SpawnInterval = 2.f;
private:

	FTimerHandle TimerHandle_Spawn;
	void SpawnAsteroid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
