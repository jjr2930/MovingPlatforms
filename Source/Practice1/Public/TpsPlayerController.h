// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TpsPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
struct FInputActionInstance;

/**
 * 
 */
UCLASS()
class PRACTICE1_API ATpsPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    void OnMove(const FInputActionValue& Value);
    void OnLook(const FInputActionValue& Value);
    void OnJump(const FInputActionValue& Value);
    void OnInteractOngoing(const FInputActionInstance& Value);
    void OnInteractCanceled(const FInputActionInstance& Value);

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Properties")
    TObjectPtr<UInputMappingContext> DefaultMappingContext;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
    TObjectPtr<UInputAction> MoveAction;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
    TObjectPtr<UInputAction> LookAction;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
    TObjectPtr<UInputAction> JumpAction;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
    TObjectPtr<UInputAction> InteractAction;
};
