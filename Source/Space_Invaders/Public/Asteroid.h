// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class SPACE_INVADERS_API AAsteroid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroid();

	UFUNCTION()
	void TakeDamageFromLaser();
	void UpdateSprite();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UPaperSpriteComponent* SpriteComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Asteroid")
	int Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asteroid")
	class UPaperSprite* Sprite1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asteroid")
	class UPaperSprite* Sprite2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asteroid")
	class UPaperSprite* Sprite3;

	UPROPERTY(EditAnywhere, Category = "Effects")
	class UNiagaraSystem* ExplosionEffect;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
