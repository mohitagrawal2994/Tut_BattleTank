// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TUT_BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 5;

public:
	void Elevate(float RelativeSpeed);
	
	
};
