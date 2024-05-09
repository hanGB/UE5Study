// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrabber::Grab()
{
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);
	DrawDebugSphere(GetWorld(), End, 10.f, 10, FColor::Blue, false, 5.f);

	// Sweep
	FCollisionShape Shpere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Shpere
	);
	if (HasHit)
	{
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Display, TEXT("Hit actor: %s"), *HitActor->GetActorNameOrLabel());
		DrawDebugSphere(GetWorld(), HitResult.Location, 10.f, 10, FColor::Green, false, 5.f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.f, 10, FColor::Yellow, false, 5.f);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No actor hit"));
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Release Grabber"));
}
