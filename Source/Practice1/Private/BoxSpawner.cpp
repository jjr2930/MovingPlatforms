// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxSpawner.h"

#include "Platform.h"
#include "Misc/MapErrors.h"

ABoxSpawner::ABoxSpawner()
	: Super()
	, CurrentLocationIndex(0)
	, SpawnDelay(1.0)
{	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);
	
	PrimaryActorTick.bCanEverTick = true;
}

void ABoxSpawner::SpawnBox()
{
	FVector CurrentLocation= this->Locations[CurrentLocationIndex];
	FRotator Rotator(0.0, 0.0, 0.0);
	GetWorld()->SpawnActor<APlatform>(Platform, CurrentLocation, Rotator);
	if (CurrentLocationIndex == Locations.Num() - 1)
	{
		SetDelayTimer();
	}
	else
	{
		CurrentLocationIndex++;
		SetSpawnTimer();
	}
}

void ABoxSpawner::SetSpawnTimer()
{	
    if(nullptr == GetWorld())
    {
        UE_LOG(LogTemp, Error, TEXT("GetWorld() is nullptr"));
        return;
    }

	GetWorld()->GetTimerManager().SetTimer(TimerHandle
		, this
		, &ABoxSpawner::SpawnBox
		, SpawnDelay
		, false); 
}

void ABoxSpawner::SetDelayTimer()
{	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle
		, [this]()
		{
			CurrentLocationIndex = 0;
			this->SetSpawnTimer();
		}
		, SpawnDelay
		, false); 
}

void ABoxSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SetSpawnTimer();
}

void ABoxSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
    
    Super::EndPlay(EndPlayReason);
}