﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"



class UInputMappingContext;
class UInputAction;


UCLASS()
class HW06_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	



public:

	AMyPlayerController();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	UInputMappingContext* InputMappingContext;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	UInputAction* SprintAction;


protected:
	virtual void BeginPlay() override;



};
