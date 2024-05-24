// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BlasterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ONLINE_FPS_API UBlasterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DelataTime) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowAbstract = "true"))
	class ABlasterCharacter* BlasterCharacter;


	UPROPERTY(BlueprintReadOnly, Category = Movment, meta = (AllowAbstract = "true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category = Movment, meta = (AllowAbstract = "true"))
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category = Movment, meta = (AllowAbstract = "true"))
	bool bIsAccelerating;


};
