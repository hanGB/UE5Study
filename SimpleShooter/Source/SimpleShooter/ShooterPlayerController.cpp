// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);

	if (bIsWinner)
	{
		UE_LOG(LogTemp, Display, TEXT("You Won The Game!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("You lost!"));
	}
}
