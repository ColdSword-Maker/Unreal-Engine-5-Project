#include "Characters/KnightCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"

AKnightCharacter::AKnightCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//CameraBoom->SetupAttachment(GetRootComponent());
	//CameraBoom->TargetArmLength = 300.f;

	//Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//Camera->SetupAttachment(CameraBoom);
	// 创建摄像机摇臂组件
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true; // 摇臂跟随控制器旋转

	// 创建摄像机组件
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // 摄像机不跟随控制器旋转，因为摇臂会旋转
	// 禁止角色直接使用控制器的旋转，这样角色就不会在移动鼠标时立即转向
	bUseControllerRotationYaw = false;

	// 启用角色朝向移动方向
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// 设置角色旋转速度
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}


void AKnightCharacter::BeginPlay()
{
	Super::BeginPlay();
	// 添加输入映射上下文
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}


void AKnightCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AKnightCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 设置增强输入
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 绑定移动动作
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKnightCharacter::Move);

		// 绑定视角旋转动作
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AKnightCharacter::Look);

		// 绑定跳跃动作
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
}

void AKnightCharacter::Move(const FInputActionValue& Value)
{
	// 获取输入向量
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// 获取控制器旋转
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// 获取前向和右向向量
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// 添加移动输入
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}


void AKnightCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// 添加控制器旋转输入
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}