// Fill out your copyright notice in the Description page of Project Settings.


#include "TranslationObject.h"

#include "SNegativeActionButton.h"

// Sets default values
ATranslationObject::ATranslationObject()
{	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRoot);	
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATranslationObject::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	
	SetNextDestination();
}

// Called every frame
void ATranslationObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Direction = Destination - GetActorLocation();
	Direction.Normalize();
	FVector Delta = Direction * MoveSpeed * DeltaTime;	
	
	AddActorLocalOffset(FVector(Delta.X, Delta.Y, Delta.Z));	
	
	FVector NowLocation = GetActorLocation();
	float RemainDistance = (Destination - NowLocation).Length();
	if (RemainDistance <= StopDistance)
	{
		FString LogMessage = FString::Printf(TEXT("Arrived! %f, %f, %f"), NowLocation.X, NowLocation.Y, NowLocation.Z );
		UE_LOG(LogTemp, Log, TEXT("%s"), *LogMessage);
		SetNextDestination();
	}
}

void ATranslationObject::SetNextDestination()
{
	float RandomRange = FMath::RandRange(0.0f, MaxRange);
	
	FVector2D RandomCircle = FMath::RandPointInCircle(RandomRange);
	
	FVector RandomCircle3D = FVector3d(RandomCircle.X, RandomCircle.Y, 0.0f);
	
	Destination = StartLocation + RandomCircle3D;	
	
	Direction = Destination - StartLocation;
}

