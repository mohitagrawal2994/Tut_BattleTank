// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* AIControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		AIControlledTank->AimAt(PlayerTank->GetActorLocation());
		AIControlledTank->Fire();
	}
}

