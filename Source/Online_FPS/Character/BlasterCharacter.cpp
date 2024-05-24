// Fill out your copyright notice in the Description page of Project Settings.





#include "BlasterCharacter.h"


#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"




// Sets default values
ABlasterCharacter::ABlasterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}
	
// Called when the game starts or when spawned
void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlasterCharacter::MoveForward(const FInputActionValue& Value)
{
	Move(Value, EAxis::X);
}

void ABlasterCharacter::MoveRight(const FInputActionValue& Value)
{
	Move(Value, EAxis::Y);
}

void ABlasterCharacter::Turn(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<FVector2D>().X);
}

void ABlasterCharacter::LookUp(const FInputActionValue& Value)
{
	AddControllerPitchInput(Value.Get<FVector2D>().X);
}

void ABlasterCharacter::Jump()
{
	ACharacter::Jump();
}

void ABlasterCharacter::Move(const FInputActionValue& Value, EAxis::Type axis)
{
	if(Controller != nullptr && Value.Get<FVector2D>().X != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(axis));
		AddMovementInput(Direction, Value.Get<FVector2D>().X);
	}
}

// Called every frame
void ABlasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	
	if(APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	if(UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputMoveForward, ETriggerEvent::Triggered, this, &ABlasterCharacter::MoveForward);

		Input->BindAction(InputMoveRight, ETriggerEvent::Triggered, this, &ABlasterCharacter::MoveRight);

		Input->BindAction(InputTurn, ETriggerEvent::Triggered, this, &ABlasterCharacter::Turn);

		Input->BindAction(InputLookUp, ETriggerEvent::Triggered, this, &ABlasterCharacter::LookUp);

		Input->BindAction(InputJump, ETriggerEvent::Triggered, this, &ABlasterCharacter::Jump);


	}





}

