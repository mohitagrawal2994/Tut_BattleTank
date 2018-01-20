// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TUT_BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

public :
	ATankPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControllerTank() const;
	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector &Hit) const;
	
	
};
