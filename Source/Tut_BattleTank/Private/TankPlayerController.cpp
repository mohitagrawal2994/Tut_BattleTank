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

