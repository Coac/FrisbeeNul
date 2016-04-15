// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "FrisbeeNul.h"
#include "FrisbeeNulPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

AFrisbeeNulPlayerController::AFrisbeeNulPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AFrisbeeNulPlayerController::BeginPlay()
{
	for (TActorIterator<AFrisbee> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, ActorItr->GetName());
		this->frisbee = *ActorItr;
	}

}

void AFrisbeeNulPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}

}

void AFrisbeeNulPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AFrisbeeNulPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AFrisbeeNulPlayerController::OnSetDestinationReleased);
	InputComponent->BindAxis("MoveForward", this, &AFrisbeeNulPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFrisbeeNulPlayerController::MoveRight);

	//Input GetFrisbeeComponent
	InputComponent->BindAction("GetFrisbeeInput", IE_Pressed, this, &AFrisbeeNulPlayerController::getFrisbee);
	InputComponent->BindAction("ReleaseFrisbeeInput", IE_Pressed, this, &AFrisbeeNulPlayerController::releaseFrisbee);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AFrisbeeNulPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AFrisbeeNulPlayerController::MoveToTouchLocation);
}

void AFrisbeeNulPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void AFrisbeeNulPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AFrisbeeNulPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AFrisbeeNulPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AFrisbeeNulPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}


void AFrisbeeNulPlayerController::MoveForward(float AxisValue)
{
	APawn* const Pawn = GetPawn();
	if (Pawn) {
		Pawn->AddMovementInput(FVector::ForwardVector, FMath::Clamp<float>(AxisValue, -1.0f, 1.0f), false);
	}
}

void AFrisbeeNulPlayerController::MoveRight(float AxisValue)
{
	APawn* const Pawn = GetPawn();
	if (Pawn) {
		Pawn->AddMovementInput(FVector::RightVector, FMath::Clamp<float>(AxisValue, -1.0f, 1.0f), false);
	}
}

void AFrisbeeNulPlayerController::getFrisbee()
{
	this->frisbee->mesh->SetSimulatePhysics(false);
	this->frisbee->AttachRootComponentToActor(GetPawn(), "", EAttachLocation::KeepWorldPosition);

	this->frisbee->SetActorRelativeLocation(FVector(0, 0, 230));
}

void AFrisbeeNulPlayerController::releaseFrisbee()
{
	this->frisbee->AttachRootComponentToActor(this->frisbee, "", EAttachLocation::KeepWorldPosition);
	this->frisbee->mesh->SetSimulatePhysics(true);

	this->frisbee->mesh->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	this->frisbee->mesh->AddForce(GetPawn()->GetActorForwardVector() * 10000000);
}
