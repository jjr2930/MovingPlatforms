// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoxSpawner.generated.h"

UCLASS()
class PRACTICE1_API ABoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxSpawner();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BoxSpawner|Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Components")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	AActor* BoxActor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	TArray<FVector> Locations;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	int CurrentLocationIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	float SpawnDelay;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	float DestroyDelay;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	float NextStepDelay;
};
