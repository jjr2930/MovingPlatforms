// Fill out your copyright notice in the Description page of Project Settings.


#include "ReciprocatingObject.h"

// Sets default values
AReciprocatingObject::AReciprocatingObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRoot);
	
	CurrentIndex = 0;
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AReciprocatingObject::BeginPlay()
{
	Super::BeginPlay();
	
	int32 Count = Locations.Num();
	if (Count <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Number of locations is 0"));
		return;
	}	
}

// Called every frame
void AReciprocatingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector CurrentDestination = Locations[CurrentIndex];
	FVector Direction = CurrentDestination - CurrentLocation;
	Direction.Normalize();
	
	FVector Delta = Direction * MovingSpeed * DeltaTime;
	
	AddActorLocalOffset(Delta);
	
	CurrentLocation = GetActorLocation();
	if ((CurrentDestination - CurrentLocation).Length() <= StopDistance)
	{
		UE_LOG(LogTemp, Error, TEXT("Arrived!"));
		CurrentIndex = (CurrentIndex + 1) % Locations.Num();
	}	
}

