// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

	APlayerController* GetTankPlayerController() const { return TankPlayerContorller; }
	bool GetAlive() const { return bAlive; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void Move(float Value);
	void Turn(float Value);

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 300.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 90.0f;

	APlayerController* TankPlayerContorller;

	bool bAlive = true;
};
