// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ShooterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintPure)
	int GetBulletsInBag() const;

	UFUNCTION(BlueprintPure)
	int GetBulletsInMagazine() const;

	void Shoot();
	void Reload();

private:
	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);
	void LookUp(const FInputActionValue& Value);
	void LookRight(const FInputActionValue& Value);
	void LookUpRate(const FInputActionValue& Value);
	void LookRightRate(const FInputActionValue& Value);

	// Inputs
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* ShooterMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveForwardAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveRightAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookUpAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookRightAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookUpRateAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookRightRateAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ShootAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* ReloadAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	float RotationRate = 10.0f;
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.0f;
	
	UPROPERTY(VisibleAnywhere)
	float Health = 100.0f;

	UPROPERTY(EditDefaultsOnly)
	float MaxBullets = 999;

	UPROPERTY(EditAnywhere)
	int Bullets = 100;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;
	UPROPERTY()
	AGun* Gun;
};
