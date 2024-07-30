// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement component"));
	ProjectileMovementComponent->MaxSpeed = 1500.0f;
	ProjectileMovementComponent->InitialSpeed = 1500.0f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NoralImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Display, TEXT("On Hit"));
	UE_LOG(LogTemp, Display, TEXT("Hit Comp: %s"), *HitComp->GetName());
	UE_LOG(LogTemp, Display, TEXT("Other Actor: %s"), *OtherActor->GetName());
	UE_LOG(LogTemp, Display, TEXT("Other Comp: %s"), *OtherComp->GetName());
}

