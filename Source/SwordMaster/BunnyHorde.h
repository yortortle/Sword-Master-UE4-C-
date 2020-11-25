// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "TimerManager.h"
//#include "BunnyTrigger.h"

#include "BunnyHorde.generated.h"

/**
 * 
 */
UCLASS()
class SWORDMASTER_API ABunnyHorde : public APaperCharacter
{
	GENERATED_BODY()

public:
	ABunnyHorde();
	ABunnyHorde(float speed);

protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor> spawnActor;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
		//APaperCharacter* BunnyTrigger;

	FTimerHandle GameTime;

	float speed = 0.0f;

	virtual void Tick(float DeltaTime) override;
};