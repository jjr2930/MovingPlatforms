// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoxSpawner.generated.h"

class APlatform;
	
UCLASS()
class PRACTICE1_API ABoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	// Sets default values for this actor's properties
	ABoxSpawner();

	void SpawnBox();
	void SetSpawnTimer();
	void SetDelayTimer();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BoxSpawner|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	TSubclassOf<APlatform> Platform;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	TArray<FVector> Locations;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	int CurrentLocationIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoxSpawner|Properties")
	float SpawnDelay;
		
	FTimerHandle TimerHandle;
};
