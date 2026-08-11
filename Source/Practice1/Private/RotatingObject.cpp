// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingObject.h"

// Sets default values
ARotatingObject::ARotatingObject()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRoot);
		
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void ARotatingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::IsNearlyZero(DeltaTime))
		return;
	
	FQuat Delta(FVector::UpVector, FMath::DegreesToRadians(RotationSpeed * DeltaTime));
	AddActorLocalRotation(Delta);
}

