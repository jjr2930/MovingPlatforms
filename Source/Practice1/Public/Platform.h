// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform.generated.h"

UCLASS()
class PRACTICE1_API APlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlatform();
	void DestroySelf();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Box Platform|Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Box Platform|Components")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Box Platform|Properties")
	float DestroyDelay;
	
	FTimerHandle TimerHandle;
};
