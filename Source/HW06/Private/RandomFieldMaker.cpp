// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomFieldMaker.h"
#include "MovingPlatformA.h"


// Sets default values
ARandomFieldMaker::ARandomFieldMaker()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomFieldMaker::BeginPlay()
{
	Super::BeginPlay();
	SpawnRandomActors();

}



void ARandomFieldMaker::SpawnRandomActors()
{
	AActor* BackSpawnedActor = nullptr;
	int TurnCount = 0;


	while (TurnCount < 100)
	{
		//☆★이전액터가 있다면 최종위치를 참조★☆

		//☆★최종위치가 극단적으로 y값을 넘어가면 안됨 그러니까 x최소전진값을 설정해야됨★☆

		//☆★y가 넘어갔다면 반대방향으로 틀 수 있게 해야됨★☆

		//☆★즉, 이동판의 y최대치는 < 최소x★☆

		//☆★최종위치부터 랜덤으로★☆








		//☆★특정 규칙하에 좌표를 랜덤으로 생성★☆

		int xx = 0;
		int yy = 0;
		bool overY = false;
		//BackSpawnedActor가 null이 아니면, 좌표를 가져오고 
		if (BackSpawnedActor != nullptr)
		{
			AMovingPlatformA* MovingPlatform = Cast<AMovingPlatformA>(BackSpawnedActor);
			{
				if (MovingPlatform)
				{
					xx = MovingPlatform->GetTargetLocation().X;
					yy = MovingPlatform->GetTargetLocation().Y;
					if (abs(yy) > MaxY)
					{
						overY = true;
					}
				}
				else
				{	
					xx = BackSpawnedActor->GetActorLocation().X;
					yy = BackSpawnedActor->GetActorLocation().Y;
				}
			}

			FVector BackActorLocation = BackSpawnedActor->GetActorLocation();
			xx = BackActorLocation.X;
			yy = BackActorLocation.Y;
		}
		//UE_LOG(LogTemp, Warning, TEXT("1.  BackSpawnedActor: xx: %d, yy: %d"), xx, yy);

		//최소 최대거리 안에 랜덤 인트값 생성
		int RandomDistance = RandomMinMeter;
		int xxx = RandomMinMeter;
		//UE_LOG(LogTemp, Warning, TEXT("2.  RandomDistance: %d, xxx: %d"), RandomDistance, xxx);
		//생성된 랜덤 인트값을 RandomMinMeter보다 큰값으로 x와 y에 배분
		FVector SpawnLocation;

		if (overY)
		{
			SpawnLocation.X = RandomMinMeter + xx;
		}
		else
		{
			RandomDistance = FMath::RandRange(RandomMinMeter, RandomMaxMeter);
			
			xxx = FMath::RandRange(RandomMinMeter, RandomDistance);
			SpawnLocation.X = xxx + xx;
		}
		//UE_LOG(LogTemp, Warning, TEXT("3.  SpawnLocation.X: %f, RandomDistance: %d, xxx: %d"), SpawnLocation.X, RandomDistance, xxx);


		//x값에서 남는 값을 y에 배분
		int yyy = GetMaxYForDiagonalDistance(xxx, RandomDistance);
		int Ys = yyy;//FMath::RandRange(0, yyy);

		//UE_LOG(LogTemp, Warning, TEXT("4.   yyy: %d, Ys: %d"), yyy, Ys);

		//Ys의 값은 양수 혹은 음수로 결정
		FMath::RandRange(0, 1) ? Ys = -Ys : Ys = Ys;

		//MaxY를 벗어나면 반대 방향으로 변경
		if (Ys + yy > MaxY)
		{
			Ys = -Ys;
		}
		else if (Ys + yy < -MaxY)
		{
			Ys = -Ys;
		}

		SpawnLocation.Y = Ys + yy;

		//UE_LOG(LogTemp, Warning, TEXT("5.   Ys:%d SpawnLocation: X: %f, Y: %f"), Ys, SpawnLocation.X, SpawnLocation.Y);

		//Z값은 고정
		

		//벡터값을 소환 위치로 정하고 ActorClassesToSpawns의 액터중 하나를 랜덤으로 선택하여 소환
		int RandomIndex = FMath::RandRange(0, ActorClassesToSpawns.Num() - 1);
		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClassesToSpawns[RandomIndex], SpawnLocation, FRotator::ZeroRotator);

		AMovingPlatformA* MovingPlatform = Cast<AMovingPlatformA>(SpawnedActor);



		//함수 종료
		if (MovingPlatform)
		{	
			MovingPlatform->RandomMovement();
			MovingPlatform->RandomMoveTime();


			if (ArrivalPoint - MovingPlatform->GetTargetLocation().X < RandomMaxMeter)
			{
				break;
			}
			
		}
		else
		{
			if (ArrivalPoint - SpawnedActor->GetActorLocation().X < RandomMaxMeter)
			{
				break;
			}
		}


		//☆★스폰된 엑터를 BackSpawnedActor로 지정★☆
		BackSpawnedActor = SpawnedActor;
		TurnCount++;
	}



	

}

int ARandomFieldMaker::GetMaxYForDiagonalDistance(const int DecidedX, const int RandomDistance)
{
	double ySquared = RandomDistance * RandomDistance - DecidedX * DecidedX;


	double y = std::sqrt(ySquared);

	//UE_LOG(LogTemp, Warning, TEXT("GetMaxYForDiagonalDistance: DecidedX: %d, RandomDistance: %d, MaxY: %f"), DecidedX, RandomDistance, y);
	return static_cast<int>(std::floor(y));
}



