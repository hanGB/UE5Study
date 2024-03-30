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

	StartLoction = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 플랫폼 앞으로 이동
		// 현재 위치 얻기
	FVector CurrentLocation = GetActorLocation();
		// 벡터를 그 위치에 더함
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
		// 그 위치를 설정
	SetActorLocation(CurrentLocation);
	// 플랫폼이 너무 멀리가면 돌아오도록 설정
		// 얼마나 이동했는지 확인
	DistanceMoved = FVector::Dist(StartLoction, CurrentLocation);
		// 너무 멀리 갔다면 움직임 방향 반대로 변경
}

