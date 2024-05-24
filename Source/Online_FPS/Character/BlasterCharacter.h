// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "InputActionValue.h"


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"

UCLASS()
class ONLINE_FPS_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);
	void LookUp(const FInputActionValue& Value);
	void Jump();

	void Move(const FInputActionValue& Value, EAxis::Type axis);






protected:


	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InputMoveForward;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InputMoveRight;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InputTurn;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InputLookUp;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* InputJump;



private:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* FollowCamera;

public:	


};
