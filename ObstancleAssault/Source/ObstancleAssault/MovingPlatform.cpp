// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �÷��� ������ �̵�
		// ���� ��ġ ���
	FVector CurrentLocation = GetActorLocation();
		// ���͸� �� ��ġ�� ����
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
		// �� ��ġ�� ����
	SetActorLocation(CurrentLocation);
	// �÷����� �ʹ� �ָ����� ���ƿ����� ����
		// �󸶳� �̵��ߴ��� Ȯ��
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		// �ʹ� �ָ� ���ٸ� ������ ���� �ݴ�� ����
	if (DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Display, TEXT("%s overshot by %f"), *Name, OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity *= -1;
	}

}

