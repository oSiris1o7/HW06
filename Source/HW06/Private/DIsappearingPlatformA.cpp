// Fill out your copyright notice in the Description page of Project Settings.


#include "DIsappearingPlatformA.h"
#include "TimerManager.h"

// Sets default values
ADIsappearingPlatformA::ADIsappearingPlatformA()
{
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	SetRootComponent(PlatformMesh);
	
}

// Called when the game starts or when spawned
void ADIsappearingPlatformA::BeginPlay()
{
	Super::BeginPlay();
	RandomDisappearTime();
	//StartLocation = GetActorLocation();
	IsDisappear = false;
	OriginalCollisionEnabled = PlatformMesh->GetCollisionEnabled();


	GetWorld()->GetTimerManager().SetTimer(
		DisappearTimerHandle,
		this,
		&ADIsappearingPlatformA::DisappearTimer,
		DisappearTime,
		true
	);
}

void ADIsappearingPlatformA::DisappearTimer()
{
	//UE_LOG(LogTemp, Warning, TEXT("DisappearTimer called"));
	if (IsDisappear)
	{	
		//SetActorLocation(StartLocation);
		IsDisappear = false;
		PlatformMesh->SetVisibility(true);
		PlatformMesh->SetCollisionEnabled(OriginalCollisionEnabled);
	}
	else
	{
		PlatformMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		PlatformMesh->SetVisibility(false);
		/*StartLocation = GetActorLocation();
		FVector NewLocation = StartLocation;
		NewLocation.Z -= DisappearZdown;
		SetActorLocation(NewLocation);*/
		IsDisappear = true;
	}	
}

void ADIsappearingPlatformA::RandomDisappearTime()
{
	DisappearTime = FMath::RandRange(DisappearTimeMin, DisappearTimeMax);
}
