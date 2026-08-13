// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyProp.h"
#include "Components/SphereComponent.h"

// Sets default values
AKeyProp::AKeyProp()
{
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

    SetRootComponent(SceneRoot);

    StaticMesh->SetupAttachment(SceneRoot);
    SphereCollision->SetupAttachment(SceneRoot);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AKeyProp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKeyProp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}