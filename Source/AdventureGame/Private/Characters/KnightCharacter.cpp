#include "Characters/KnightCharacter.h"


AKnightCharacter::AKnightCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}


void AKnightCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AKnightCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AKnightCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

