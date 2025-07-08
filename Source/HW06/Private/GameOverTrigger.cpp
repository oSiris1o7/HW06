// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h" 
#include "Camera/CameraComponent.h"

// Sets default values
AGameOverTrigger::AGameOverTrigger()
{

}

// Called when the game starts or when spawned
void AGameOverTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}


void AGameOverTrigger::GameOverBegin()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(PlayerController ? PlayerController->GetPawn() : nullptr);

	if (PlayerController && PlayerCharacter)
	{
		PlayerController->DisableInput(PlayerController);
		PlayerCharacter->DisableInput(PlayerController);


		PlayerCharacter->bUseControllerRotationPitch = false;
		PlayerCharacter->bUseControllerRotationYaw = false;
		PlayerCharacter->bUseControllerRotationRoll = false;


		USpringArmComponent* SpringArm = PlayerCharacter->SpringArmComponent;
		UCameraComponent* Camera = PlayerCharacter->CameraComponent;

		if (SpringArm && Camera)
		{
			SpringArm->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
			SpringArm->bUsePawnControlRotation = false;


			//높이 조정? 현재 100으로 고정되잇으니까 변경바람..

			FVector CurrentCameraLocation = Camera->GetComponentLocation();
			Camera->SetWorldLocation(FVector(CurrentCameraLocation.X, CurrentCameraLocation.Y, 100.0f));

		}






	}

}
