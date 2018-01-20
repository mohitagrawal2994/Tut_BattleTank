// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr) { return; }
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO Player Tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s : Player Tank found"),*PlayerTank->GetName());
	}
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
