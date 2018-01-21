// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Did not get the pawn"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Got the pawn : %s"),*ControlledTank->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
}

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATankPlayerController::ATankPlayerController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if(!GetControllerTank())
	{
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControllerTank()->AimAt(HitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	///Find The crosshair position in pixel coordinates i.e find the aim dot location in 2d space as it can vary due to screen size
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	///De-Project Screen Position to world i.e find the 3d vector to the direction in which the tank is looking taking camera as origin 
	FVector CameraWorldLocation, WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
	{		
		///Line Trace along the world direction to return the first object we hit
		FHitResult HitResult;
		FVector StartLocation = PlayerCameraManager->GetCameraLocation();
		FVector EndLocation = StartLocation + (WorldDirection*LineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
		{
			HitLocation = HitResult.Location;
			return true;
		}
		HitLocation = FVector(0);
		return true;
	}
	return false;
}
