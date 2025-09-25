// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Asteroid.h"
#include "Spaceship.h"
// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick(s) every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;


    SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
    SpriteComponent->SetupAttachment(RootComponent);

    CollisionBox->OnComponentHit.AddDynamic(this, &ALaser::OnHit);
    CollisionBox->SetNotifyRigidBodyCollision(true);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 1000.f;
    ProjectileMovement->MaxSpeed = 1000.f;
    ProjectileMovement->bRotationFollowsVelocity = false;
    ProjectileMovement->bShouldBounce = false;
    ProjectileMovement->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaser::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, FVector NormalImpulse,
    const FHitResult& Hit)
{
    if (OtherActor && OtherActor != this)
    {
        if (OtherActor->IsA(AAsteroid::StaticClass()))
        {
            AAsteroid* HitAsteroid = Cast<AAsteroid>(OtherActor);
            HitAsteroid->TakeDamageFromLaser();
            Destroy();
        }
    }
}