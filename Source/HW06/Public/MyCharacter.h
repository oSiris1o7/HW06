// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;


UCLASS()
class HW06_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartJump(const FInputActionValue& Value);
	void StopJump(const FInputActionValue& Value);
	void StartSprint(const FInputActionValue& Value);
	void StopSprint(const FInputActionValue& Value);



	//USpringArmComponent* GetSpringArm();



	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float NormalSpeed;
	float SprintSpeed;
	float SprintMultiplier;



};
