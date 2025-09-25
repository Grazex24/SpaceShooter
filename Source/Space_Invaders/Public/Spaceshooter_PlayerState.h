// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Spaceshooter_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SPACE_INVADERS_API ASpaceshooter_PlayerState : public APlayerState
{
	GENERATED_BODY()
public:
    ASpaceshooter_PlayerState();

    UPROPERTY(BlueprintReadOnly, Category = "Score")
    int MyScore;

    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int Points);

    UFUNCTION(BlueprintCallable, Category = "Score")
    FString GetScoreText() const;
};
