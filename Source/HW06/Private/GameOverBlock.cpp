// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverBlock.h"
#include "GameOverTrigger.h"
#include "MyCharacter.h"


// Sets default values
AGameOverBlock::AGameOverBlock()
{
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh"));
	SetRootComponent(BlockMesh);

	// 콜리전 설정
	BlockMesh->SetGenerateOverlapEvents(true);
	BlockMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BlockMesh->SetCollisionObjectType(ECC_WorldStatic);
	BlockMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	BlockMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);


}

// Called when the game starts or when spawned
void AGameOverBlock::BeginPlay()
{
	Super::BeginPlay();

	BlockMesh->OnComponentBeginOverlap.AddDynamic(this, &AGameOverBlock::OnOverlapBegin);

}




void AGameOverBlock::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("GameOverBlock: 오버랩 발생! OtherActor: %s"), *GetNameSafe(OtherActor));
}
