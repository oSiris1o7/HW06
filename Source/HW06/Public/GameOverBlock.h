// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"


#include "GameOverTrigger.h"


#include "GameOverBlock.generated.h"
UCLASS()
class HW06_API AGameOverBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameOverBlock();

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* BlockMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	


	UPROPERTY(EditAnywhere, Category = "Mesh")
	AGameOverTrigger* LinkedGameOverTrigger;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
