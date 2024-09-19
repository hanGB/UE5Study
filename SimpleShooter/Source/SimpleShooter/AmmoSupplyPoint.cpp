// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoSupplyPoint.h"
#include "Components/BoxComponent.h"
#include "ShooterCharacter.h"
#include "ShooterPlayerController.h"

// Sets default values
AAmmoSupplyPoint::AAmmoSupplyPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>("Box Mesh");
	RootComponent = BoxMesh;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	BoxCollision->SetupAttachment(BoxMesh);
}

// Called when the game starts or when spawned
void AAmmoSupplyPoint::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->SetGenerateOverlapEvents(true);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AAmmoSupplyPoint::OnBoxCollisionOverlap);
}

// Called every frame
void AAmmoSupplyPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmoSupplyPoint::OnBoxCollisionOverlap(UPrimitiveComponent* OverlapComponenet, AActor* OtherActor,UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AShooterCharacter* ShooterCharacter = Cast<AShooterCharacter>(OtherActor);
	if (!ShooterCharacter)
	{
		return;
	}
	AShooterPlayerController* PlayerController = Cast<AShooterPlayerController>(ShooterCharacter->GetController());
	if (!PlayerController)
	{
		return;
	}

	if (!ShooterCharacter->AddAmmo(Ammo))
	{
		return;
	}

	if (BoxMesh && OpenedBoxMesh)
	{
		BoxMesh->SetStaticMesh(OpenedBoxMesh);
	}
	BoxCollision->OnComponentBeginOverlap.Clear();
	BoxCollision->SetGenerateOverlapEvents(false);
}

