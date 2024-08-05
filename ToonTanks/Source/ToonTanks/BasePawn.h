// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	virtual void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget);
	void RotateTurretVertical(float Value);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurretRotationSpeed = 5.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurretVerticalRotationSpeed = 5.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaximumTurretVerticalRotation = 15.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Combet")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category = "Combet")
	UParticleSystem* DeathParticle;

	UPROPERTY(EditAnywhere, Category = "Combet")
	USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Combet")
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;
};
