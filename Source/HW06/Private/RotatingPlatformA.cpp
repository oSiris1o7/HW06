// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatformA.h"

// Sets default values
ARotatingPlatformA::ARotatingPlatformA()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	SetRootComponent(PlatformMesh);


}

// Called when the game starts or when spawned
void ARotatingPlatformA::BeginPlay()
{
	Super::BeginPlay();
	
	RandomRotation();

	FVector Location = GetActorLocation();
	Location.Z = ZPosition;
	SetActorLocation(Location);
}

// Called every frame
void ARotatingPlatformA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator CurrentRotation = PlatformMesh->GetRelativeRotation();

	FRotator RotationDelta = FRotator(RotationSpeed.X * DeltaTime, RotationSpeed.X * DeltaTime, RotationSpeed.Z * DeltaTime);

	CurrentRotation += RotationDelta;

	PlatformMesh->SetRelativeRotation(CurrentRotation);
}

void ARotatingPlatformA::RandomRotation()
{
	RotationSpeed = FVector(0, 0, 0);
	if (HoldRotationX == false)
	{
		RotationSpeed.X = FMath::RandRange(RotationTimeMin, RotationTimeMax);
	}
	if (HoldRotationY == false)
	{
		RotationSpeed.Y = FMath::RandRange(RotationTimeMin, RotationTimeMax);
	}
	if (HoldRotationZ == false)
	{
		RotationSpeed.Z = FMath::RandRange(RotationTimeMin, RotationTimeMax);
	}

}