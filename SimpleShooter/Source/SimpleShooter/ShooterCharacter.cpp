// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Gun.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Set Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem 
			= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(ShooterMappingContext, 0);
		}
	}

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	// Add socket at weapon_r bone
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AShooterCharacter::MoveForward);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AShooterCharacter::MoveRight);
		EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookUp);
		EnhancedInputComponent->BindAction(LookRightAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookRight);
		EnhancedInputComponent->BindAction(LookUpRateAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookUpRate);
		EnhancedInputComponent->BindAction(LookRightRateAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookRightRate);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	}
}

void AShooterCharacter::MoveForward(const FInputActionValue& Value)
{
	AddMovementInput(GetActorForwardVector() * Value.Get<float>());
}

void AShooterCharacter::MoveRight(const FInputActionValue& Value)
{
	AddMovementInput(GetActorRightVector() * Value.Get<float>());
}

void AShooterCharacter::LookUp(const FInputActionValue& Value)
{
	AddControllerPitchInput(Value.Get<float>());
}

void AShooterCharacter::LookRight(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<float>());
}

void AShooterCharacter::LookUpRate(const FInputActionValue& Value)
{
	AddControllerPitchInput(Value.Get<float>() * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookRightRate(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<float>() * RotationRate * GetWorld()->GetDeltaSeconds());
}
