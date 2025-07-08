// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomFieldMaker.generated.h"

UCLASS()
class HW06_API ARandomFieldMaker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomFieldMaker();
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Spawns")
	TArray<TSubclassOf<class AActor>> ActorClassesToSpawns;


	UPROPERTY(EditAnywhere, Category = "Spawns")
	int ArrivalPoint;


	void SpawnRandomActors();

	int GetMaxYForDiagonalDistance(const int DecidedX, const int RandomDistance);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	UPROPERTY(EditAnywhere, Category = "Spawns")
	int RandomMinMeter;
	UPROPERTY(EditAnywhere, Category = "Spawns")
	int RandomMaxMeter;
	
	UPROPERTY(EditAnywhere, Category = "Spawns")
	int MaxY;
	/*UPROPERTY(EditAnywhere, Category = "Spawns")
	int MoveMaxPlus;*/

	
	

};
