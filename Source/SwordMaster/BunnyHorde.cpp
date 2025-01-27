#define debugPrint(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define debugPrintFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))
// Fill out your copyright notice in the Description page of Project Settings.


#include "BunnyHorde.h"

ABunnyHorde::ABunnyHorde()
{

}

ABunnyHorde::ABunnyHorde(float s1)
{
	speed = s1;
}

void ABunnyHorde::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	GameInstance = Cast<USwordGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
}

void ABunnyHorde::Tick(float DeltaTime)
{
	//this is an insane of the always updated FVector location that swordman puts out when he moves around.
	FVector NewLocation = GameInstance->SwordManLocation;
	CurrentLocation = this->GetActorLocation();

	//how to determine the bunnies movement being tracked to the play.
	if (CurrentLocation.X < NewLocation.X)
	{
		CurrentLocation.X += 40 * DeltaTime;

		//assigns A to whichever if statementi s ran, used to determine flipbook priority later.
		one = true;
		A = NewLocation.X - CurrentLocation.X;
	}
	if (CurrentLocation.X > NewLocation.X)
	{
		CurrentLocation.X -= 40 * DeltaTime;

		two = true;
		A = CurrentLocation.X - NewLocation.X;
	}
	if (CurrentLocation.Z < NewLocation.Z)
	{
		//debugPrint("Z is different");
		CurrentLocation.Z += 40 * DeltaTime;
		B = NewLocation.Z - CurrentLocation.Z;

		three = true;
	}
	if (CurrentLocation.Z > NewLocation.Z)
	{
		CurrentLocation.Z -= 40 * DeltaTime;
		B = CurrentLocation.Z - NewLocation.Z;

		four = true;
	}

	if (A > B && one == true)
	{
		//debugPrint("X is larger than Z");
		GetSprite()->SetFlipbook(MoveRight);
	}
	else if (A > B && two == true)
	{
		GetSprite()->SetFlipbook(MoveLeft);
	}
	else if (B > A&& three == true)
	{
		GetSprite()->SetFlipbook(MoveUp);
	}
	else if (B > A&& four == true)
	{
		GetSprite()->SetFlipbook(MoveDown);
	}

	one = false;
	two = false;
	three = false;
	four = false;
	SetActorLocation(CurrentLocation);
}

