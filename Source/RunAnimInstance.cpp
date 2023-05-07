// Fill out your copyright notice in the Description page of Project Settings.


#include "RunAnimInstance.h"

#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void URunAnimInstance::NativeInitializeAnimation()
{
	if(Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	
	//check again if it's a nullptr or not 
	if(IsValid(Pawn))
	{
		MovementComponent = Pawn->GetMovementComponent();
	}
}

void URunAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if(Pawn && MovementComponent)
	{
		bIsInAir = MovementComponent->IsFalling();
		
		//UKismetMathLibrary::VSize(Pawn->GetVelocity());
		
		//the following same as above and more readable for me
		Speed = Pawn->GetVelocity().Size();
	}
}
