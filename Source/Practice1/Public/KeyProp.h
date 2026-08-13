// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyProp.generated.h"

class USphereComponent;
UCLASS()
class PRACTICE1_API AKeyProp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyProp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "KeyProp|Components")
    TObjectPtr<USceneComponent> SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "KeyProp|Components")
    TObjectPtr<UStaticMeshComponent> StaticMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "KeyProp|Components")
    TObjectPtr<USphereComponent> SphereCollision;
};
