// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxSpawner.h"

#include "Misc/MapErrors.h"

ABoxSpawner::ABoxSpawner()
	: Super()
	, CurrentLocationIndex(0)
{	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(SceneRoot);
	
	//GetWorld()->GetTimerManager().SetTimer()
	
	PrimaryActorTick.bCanEverTick = true;
}