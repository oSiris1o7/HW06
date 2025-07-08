// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController() :
	InputMappingContext(nullptr),
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr)
{

}



void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();


	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsytem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				
				Subsytem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}



