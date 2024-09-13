// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior)
	{
		RunBehaviorTree(AIBehavior);
	}
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AShooterAIController::IsDead() const
{
	if (AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn()))
	{
		return ControlledCharacter->IsDead();
	}

	return true;
}

