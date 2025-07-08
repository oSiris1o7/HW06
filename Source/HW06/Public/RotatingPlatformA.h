// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatformA.generated.h"

UCLASS()
class HW06_API ARotatingPlatformA : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotatingPlatformA();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RandomRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FVector RotationSpeed;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool HoldRotationX;
	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool HoldRotationY;
	UPROPERTY(EditAnywhere, Category = "Rotation")
	bool HoldRotationZ;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationTimeMin;
	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationTimeMax;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float ZPosition;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* PlatformMesh;



};
