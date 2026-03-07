#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KnightCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ADVENTUREGAME_API AKnightCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AKnightCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

private:




};
