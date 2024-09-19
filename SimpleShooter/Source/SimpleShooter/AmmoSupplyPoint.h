// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmmoSupplyPoint.generated.h"

UCLASS()
class SIMPLESHOOTER_API AAmmoSupplyPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmoSupplyPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBoxCollisionOverlap(UPrimitiveComponent* OverlapComponenet, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* BoxMesh;

	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* BoxCollision;

	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* OpenedBoxMesh;

	UPROPERTY(EditAnywhere)
	int Ammo = 100;
};
