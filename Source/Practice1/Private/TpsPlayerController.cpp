// Fill out your copyright notice in the Description page of Project Settings.


#include "TpsPlayerController.h"
#include "EnhancedInputSubsystems.h"

void ATpsPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (!DefaultMappingContext)
    {
        UE_LOG(LogTemp, Warning, TEXT("Default Mapping context is invalid"));

        return;
    }

    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem
            = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

void ATpsPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent(); 
}
