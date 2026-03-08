#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KnightCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
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

protected:

    // 输入映射上下文
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    // 移动输入动作
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* MoveAction;

    // 视角旋转输入动作
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* LookAction;

    // 跳跃输入动作
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* JumpAction;

    // 移动处理函数
    void Move(const FInputActionValue& Value);

    // 视角旋转处理函数
    void Look(const FInputActionValue& Value);

    // 跳跃处理函数
    void Jump(const FInputActionValue& Value);


};
