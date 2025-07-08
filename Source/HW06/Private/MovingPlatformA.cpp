// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformA.h"
#include "RandomFieldMaker.h"

// Sets default values
AMovingPlatformA::AMovingPlatformA()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	SetRootComponent(PlatformMesh);

	//StartLocation = GetActorLocation();
	//TargetLocation = StartLocation + MovingLocation;

	bMovingToStart = false;
	ElapsedMoveTime = 0.0f;
}

// Called when the game starts or when spawned
void AMovingPlatformA::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovingPlatformA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//목표는 스타트나 TargetLocation으로,  bool로 통제
	//틱마다 목표지점으로 이동 
	//무빙로케이션을 MovingSpeed 시간안에 도달하도록 설정

	if (bMovingToStart)
	{
		ElapsedMoveTime -= DeltaTime;
		if (ElapsedMoveTime <= 0.0f)
		{
			ElapsedMoveTime = 0.0f;
			bMovingToStart = false;
		}
	}
	else
	{
		ElapsedMoveTime += DeltaTime;
		if (ElapsedMoveTime >= MovingTime)
		{
			ElapsedMoveTime = MovingTime;
			bMovingToStart = true;
		}
	}


	float Alpha = ElapsedMoveTime / MovingTime;
	FVector NewLocation = FMath::Lerp(StartLocation, TargetLocation, Alpha);
	SetActorLocation(NewLocation);
}


void AMovingPlatformA::RandomMovement()
{
	FVector StartLocationFake = GetActorLocation();
	StartLocationFake.Z = ZPosition;

	StartLocation = StartLocationFake;

	MovingLocation.X = FMath::RandRange(RandomMovingMin, RandomMovingMax);
	MovingLocation.Y = MyRandomFieldMakerActor->GetMaxYForDiagonalDistance(MovingLocation.X, RandomMovingMax);
	MovingLocation.Z = 0.0f;
	TargetLocation = StartLocation + MovingLocation;
}
void AMovingPlatformA::RandomMoveTime()
{
	MovingTime = FMath::RandRange(RandomTimeMin, RandomTimeMax);
}
FVector AMovingPlatformA::GetTargetLocation() const
{
	return TargetLocation;
}

int AMovingPlatformA::GetZPosition() const
{
	return ZPosition;
}

