// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "KnightAnimInstance.generated.h"
class AKnightCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class ADVENTUREGAME_API UKnightAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	AKnightCharacter* Knight;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UCharacterMovementComponent* KnightCharacterMovement;


	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float Speed;


	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsFalling;


};


