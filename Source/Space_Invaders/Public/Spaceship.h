// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spaceship.generated.h"


UCLASS()
class SPACE_INVADERS_API ASpaceship : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	ASpaceship();

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Combat")
	int CurrentLives = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UPaperSpriteComponent* SpriteComponent;

private:

	void Shoot();

	void MoveRight(float value);
	void MoveUp(float value);

	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* FloatingMovement;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class ALaser> LaserClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
