// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReciprocatingObject.generated.h"

UCLASS()
class PRACTICE1_API AReciprocatingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReciprocatingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ReciprocatingObject|Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ReciprocatingObject|Components")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ReciprocatingObject|Properties")
	TArray<FVector> Locations;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ReciprocatingObject|Properties")
	float MovingSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ReciprocatingObject|Properties")
	float StopDistance;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ReciprocatingObject|Properties")
	int CurrentIndex;
};
