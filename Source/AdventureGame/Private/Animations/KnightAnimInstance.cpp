// 此次遇到的问题
// 1、角色fallloop动画和land动画需要设置两个属性：
// (1)、附加设置：无additive
// (2)、强制根锁定
// 具体原因是：由于角色的骨骼网格体有碰撞，这个碰撞会与胶囊体的碰撞冲突，当动画导致骨骼网格体发生位移的时候
// 渲染就会出问题


#include "Animations/KnightAnimInstance.h"
#include "Characters/KnightCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
void UKnightAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Knight = Cast<AKnightCharacter>(TryGetPawnOwner());
	if (Knight)
	{
		KnightCharacterMovement = Knight->GetCharacterMovement();
	}
}

void UKnightAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (Knight != nullptr && KnightCharacterMovement!= nullptr)
	{
		Speed = UKismetMathLibrary::VSizeXY(KnightCharacterMovement->Velocity);
		bIsFalling = Knight->GetCharacterMovement()->IsFalling();
	}
	
}
