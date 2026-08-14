// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TpsPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class USphereComponent;
class UMainUI;
class AKeyProp;
struct FInputActionInstance;

UCLASS()
class PRACTICE1_API ATpsPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ATpsPlayer();

	void OnMove(const FInputActionValue& Value);
	void OnLook(const FInputActionValue& Value);
    void OnJump(const FInputActionValue& Value);
    void OnInteractOngoing(const FInputActionInstance& Value);
    void OnInteractCanceled(const FInputActionInstance& Value);

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp
        , class AActor* OtherActor
        , class UPrimitiveComponent* OtherComponent
        , int32 OtherBodyIndex
        , bool bFromSweep
        , const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp
        , class AActor* OtherActor
        , class UPrimitiveComponent* OtherComponent
        , int32 OtherBodyIndex);

    
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|Components")
	TObjectPtr<UCameraComponent> Camera;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|Interactions")
    TObjectPtr<USphereComponent> InteractionCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|Interactions")
    TObjectPtr<AKeyProp> KeyProp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|Interactions")
    float InteractionTargetElapsedTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|UI")
    TSubclassOf<UMainUI> MainUiClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TpsPlayer|Level")
    TSoftObjectPtr<UWorld> CongratulationLevel;

    TObjectPtr<UMainUI> MainUiInstance;
    bool IsFinished;
};
