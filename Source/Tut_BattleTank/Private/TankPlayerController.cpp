// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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
}
