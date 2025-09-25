// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceshooter_PlayerState.h"
#include "Math/UnrealMathUtility.h"

ASpaceshooter_PlayerState::ASpaceshooter_PlayerState()
{
    // Valeur initiale
    MyScore = 0;
}

void ASpaceshooter_PlayerState::AddScore(int Points)
{
    MyScore += Points;
}

FString ASpaceshooter_PlayerState::GetScoreText() const
{
    return FString::Printf(TEXT("Score: %d"), MyScore);
}