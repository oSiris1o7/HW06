// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DIsappearingPlatformA.generated.h"

UCLASS()
class HW06_API ADIsappearingPlatformA : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADIsappearingPlatformA();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float DisappearTime;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float DisappearTimeMin;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float DisappearTimeMax;


	//UPROPERTY(EditAnywhere, Category = "Movement")
	//float DisappearZdown;
	
	//FVector StartLocation;

	bool IsDisappear = true;


	FTimerHandle DisappearTimerHandle;
	UFUNCTION()
	void DisappearTimer();
	void RandomDisappearTime();
	


	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* PlatformMesh;


	ECollisionEnabled::Type OriginalCollisionEnabled;

};
