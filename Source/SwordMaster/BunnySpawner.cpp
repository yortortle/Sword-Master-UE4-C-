#define debugPrint(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define debugPrintFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

// Fill out your copyright notice in the Description page of Project Settings.


#include "BunnySpawner.h"
#include "BunnyHorde.h"

// Sets default values
ABunnySpawner::ABunnySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABunnySpawner::BeginPlay()

{
	Super::BeginPlay();
	//debugPrint("bunny begin play");
	GameInstance = Cast<USwordGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
}

// Called every frame
void ABunnySpawner::Tick(float DeltaTime)
{
	if (!(HasSpawnerRan))
	{
		//if global timer is active spawns horde
		if (GetWorldTimerManager().IsTimerActive(GameInstance->BunnySpawner))
		{
			SpawnBunny();
			HasSpawnerRan = true;
		}
	}
	Super::Tick(DeltaTime);
}

void ABunnySpawner::SpawnBunny()
{
	//debugPrint("Actor should be spawning");
	FVector SpawnLocation = this->GetActorLocation();
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AActor>(ToSpawn, SpawnLocation, this->GetActorRotation(), SpawnParams);
}