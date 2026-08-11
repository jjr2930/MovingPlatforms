// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TranslationObject.generated.h"

UCLASS()
class PRACTICE1_API ATranslationObject : public AActor
{
	GENERATED_BODY()

public:
	
public:	
	// Sets default values for this actor's properties
	ATranslationObject();

public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	
protected:
	void SetNextDestination();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RotatingObject:Component")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RotatingObject:Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RotatingObject:Properties")
	FVector StartLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RotatingObject:Properties")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RotatingObject:Properties")
	float MaxRange;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RotatingObject:Properties")
	FVector Direction;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RotatingObject:Properties")
	FVector Destination;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RotatingObject:Properties")
	float StopDistance;
};