// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	//Ask The Aiming Component To aim at the tank
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{ 
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("At %f Tank Fire"), GetWorld()->GetDeltaSeconds());
	if (!Barrel) { return; }

	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")),Barrel->GetSocketRotation(FName("Projectile")));
}

