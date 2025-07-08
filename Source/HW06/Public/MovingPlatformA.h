// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomFieldMaker.h"
#include "MovingPlatformA.generated.h"


UCLASS()
class HW06_API AMovingPlatformA : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatformA();
	virtual void Tick(float DeltaTime) override;

	void RandomMovement();
	void RandomMoveTime();
	FVector GetTargetLocation() const;
	int GetZPosition() const;
	ARandomFieldMaker* MyRandomFieldMakerActor;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MovingLocation;	//이동거리
	FVector StartLocation;	//시작지점
	FVector TargetLocation;	//목표지점

	UPROPERTY(EditAnywhere, Category = "Movement")
	int RandomMovingMin;
	UPROPERTY(EditAnywhere, Category = "Movement")
	int RandomMovingMax;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovingTime;	//이동시간
	float ElapsedMoveTime;	//경과시간

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RandomTimeMin;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RandomTimeMax;


	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bMovingToStart; //이동할 방향

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ZPosition;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* PlatformMesh;



};
