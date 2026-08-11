// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform.h"


// Sets default values
APlatform::APlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	RootComponent = SceneRoot;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle
		, this
		, &APlatform::DestroySelf
		, DestroyDelay);
}

void APlatform::DestroySelf()
{
	Destroy();
}

