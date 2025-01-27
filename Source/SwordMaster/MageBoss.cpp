// Fill out your copyright notice in the Description page of Project Settings.


#include "MageBoss.h"


AMageBoss::AMageBoss()
{
	//PrimaryActorTick.bCanEverTick = true;
}

void AMageBoss::BeginPlay()
{
	Super::BeginPlay();
	GameInstance = Cast<USwordGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UE_LOG(LogTemp, Warning, TEXT("StartMageBoss"));
	GetWorldTimerManager().SetTimer(WalkTimer, this, &AMageBoss::BossWalk, 1, true);
	GetWorldTimerManager().SetTimer(ProjectileTimer, this, &AMageBoss::shootProjectile, 0.15, true);
	GetWorldTimerManager().SetTimer(EndTimer, this, &AMageBoss::endFight, 10, true);
}

void AMageBoss::Tick(float DeltaTime)
{
	if (GetWorldTimerManager().IsTimerActive(WalkTimer))
	{
		switch (MoveDirection)
		{
			case 0: 
			{
				CurrentLocationTwo = this->GetActorLocation();
				if (GetWorldTimerManager().IsTimerActive(CutsceneTimer))
				{
					speed = 120;
				}
				else
				{
					speed = 350;
				}
				CurrentLocationTwo.X -= speed * DeltaTime;
				SetActorLocation(CurrentLocationTwo);
			}
			break;
			case 1:
			{
				CurrentLocationTwo = this->GetActorLocation();
				if (GetWorldTimerManager().IsTimerActive(CutsceneTimer))
				{
					speed = 120;
				}
				else
				{
					speed = 350;
				}
				CurrentLocationTwo.X += speed * DeltaTime;
				SetActorLocation(CurrentLocationTwo);
			}
			break;
		}
	}
}

void AMageBoss::BossWalk()
{
	UE_LOG(LogTemp, Warning, TEXT("Mage Changing Directions"));

	switch (MoveDirection)
	{
		case 0:
		{
			GetSprite()->SetFlipbook(MoveRight);
			MoveDirection = 1;
		}
		break;
		case 1:
		{
			GetSprite()->SetFlipbook(MoveLeft);
			MoveDirection = 0;
		}
		break;
	}
}

void AMageBoss::shootProjectile()
{
	UE_LOG(LogTemp, Warning, TEXT("shooting projectile"));

	SpawnLocation = this->GetActorLocation();
	SpawnLocation.Z -= 25;
	FActorSpawnParameters SpawnParams;
	
	GetWorld()->SpawnActor<AActor>(ActorSpawn, SpawnLocation, this->GetActorRotation(), SpawnParams);
	UE_LOG(LogTemp, Warning, TEXT("ice should be shooting"));
}

void AMageBoss::endFight()
{
	GetWorldTimerManager().SetTimer(CutsceneTimer, this, &AMageBoss::Cutscene, 5, true);
	GetWorldTimerManager().ClearTimer(ProjectileTimer);
}

void AMageBoss::Cutscene()
{
	GameInstance->mageCompleted = true;
}