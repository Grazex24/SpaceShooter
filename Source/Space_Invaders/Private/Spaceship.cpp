// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"
#include "Laser.h"
#include "Asteroid.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Blueprint/UserWidget.h" 
#include "PaperSpriteComponent.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
    SpriteComponent->SetupAttachment(RootComponent);

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingMovement->MaxSpeed = 600.f;   // vitesse max
	FloatingMovement->Acceleration = 2000.f; // accélération
	FloatingMovement->Deceleration = 2000.f; // décélération

}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASpaceship::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &ASpaceship::MoveUp);
    PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ASpaceship::Shoot);
}

void ASpaceship::Shoot()
{
    if (LaserClass)
    {
        FVector MuzzleLocation = GetActorLocation() ;
        FRotator MuzzleRotation = GetActorRotation();

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;

        ALaser* Projectile = GetWorld()->SpawnActor<ALaser>(LaserClass, MuzzleLocation, MuzzleRotation, SpawnParams);
        if (Projectile)
        {
            // Définir la velocity dans la direction du vaisseau
            FVector ShootDirection = GetActorForwardVector();
            Projectile->ProjectileMovement->Velocity = ShootDirection * Projectile->ProjectileMovement->InitialSpeed;
            Projectile->SetLifeSpan(1.0f);
        }
    }
}

void ASpaceship::MoveRight(float Value)
{
	if (Value != 0.f)
		AddMovementInput(FVector::ForwardVector, Value);
}

void ASpaceship::MoveUp(float Value)
{
	if (Value != 0.f)
		AddMovementInput(FVector::RightVector, -Value);
}