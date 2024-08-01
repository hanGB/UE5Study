// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

protected:
	virtual void BeginPlay() override;
	
private:
	void CheckFireCondition();

	bool IsTankInFireRange() const;

	class ATank* Tank;

	UPROPERTY(EditAnywhere, Category = "Combet")
	float FireRange = 1000.0f;

	FTimerHandle FireRateTimeHandle;
	float FireRate = 2.f;
};
