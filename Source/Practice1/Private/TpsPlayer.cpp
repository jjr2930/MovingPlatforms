// Fill out your copyright notice in the Description page of Project Settings.


#include "TpsPlayer.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.h"
#include "KeyProp.h"
#include "MainUI.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ATpsPlayer::ATpsPlayer()
    : KeyProp(nullptr)
    , IsFinished(false)
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    InteractionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Interact Collision"));

    SpringArm->SetupAttachment(this->GetCapsuleComponent());
    Camera->SetupAttachment(SpringArm);
    InteractionCollision->SetupAttachment(this->GetCapsuleComponent()); 

    InteractionCollision->OnComponentBeginOverlap.AddDynamic(this, &ATpsPlayer::OnOverlapBegin);
    InteractionCollision->OnComponentEndOverlap.AddDynamic(this, &ATpsPlayer::OnOverlapEnd);

    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void ATpsPlayer::BeginPlay()
{
    Super::BeginPlay();

    //add input system to subsystem
    APlayerController* PlayerController = Cast<APlayerController>(Controller);
    if (nullptr == PlayerController)
    {
        UE_LOG(LogTemp, Error, TEXT("PlayerController is nullptr."));
        return;
    }

    UEnhancedInputLocalPlayerSubsystem* SubSystem
        = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
            PlayerController->GetLocalPlayer());

    if (nullptr == SubSystem)
    {
        UE_LOG(LogTemp, Error, TEXT("PlayerController is nullptr."));
        return;
    }

    if (nullptr == DefaultMappingContext)
    {
        UE_LOG(LogTemp, Error, TEXT("DefaultMappingContext is nullptr."));
        return;
    }

    SubSystem->AddMappingContext(DefaultMappingContext, 0);

    if (nullptr == MainUiClass)
    {
        UE_LOG(LogTemp, Error, TEXT("Main Ui is nullptr"));
        return;
    }

    MainUiInstance = CreateWidget<UMainUI>(GetWorld(), MainUiClass);
    if(nullptr == MainUiInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("MainUiInstance is nullptr."));
        return;
    }

    MainUiInstance->AddToViewport();
    MainUiInstance->SetVisibilities(ESlateVisibility::Hidden
        , ESlateVisibility::Hidden, ESlateVisibility::Hidden);
}

void ATpsPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* EnhancedInput
        = Cast<UEnhancedInputComponent>(PlayerInputComponent);

    if (nullptr == EnhancedInput)
    {
        UE_LOG(LogTemp, Error, TEXT("EnhancedInput is nullptr."));
        return;
    }

    EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATpsPlayer::OnMove);
    EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATpsPlayer::OnLook);
    EnhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ATpsPlayer::OnJump);
    EnhancedInput->BindAction(InteractAction, ETriggerEvent::Ongoing, this, &ATpsPlayer::OnInteractOngoing);
    EnhancedInput->BindAction(InteractAction, ETriggerEvent::Canceled, this, &ATpsPlayer::OnInteractCanceled);
}

void ATpsPlayer::OnMove(const FInputActionValue& Value)
{
    AddMovementInput(GetActorForwardVector(), Value.Get<FVector2D>().Y);
    AddMovementInput(GetActorRightVector(), Value.Get<FVector2D>().X);
}

void ATpsPlayer::OnLook(const FInputActionValue& Value)
{
    AddControllerYawInput(Value.Get<FVector2D>().X);
    AddControllerPitchInput(Value.Get<FVector2D>().Y);
}

void ATpsPlayer::OnJump(const FInputActionValue& Value)
{
    if (this->CanJump())
    {
        Super::Jump();
    }
}

void ATpsPlayer::OnInteractOngoing(const FInputActionInstance& Value)
{
    if (nullptr == KeyProp)
    {
        UE_LOG(LogTemp, Warning, TEXT("Keyprop is nullptr")); 
        return;
    }
    
    if (FMath::IsNearlyZero(InteractionTargetElapsedTime))
    {
        UE_LOG(LogTemp, Error, TEXT("InteractionTargetElapsedTime is zero"));   
        return;
    }

    float ElapsedTime = Value.GetElapsedTime();
    float Percent = ElapsedTime/ InteractionTargetElapsedTime;

    MainUiInstance->SetVisibilities(ESlateVisibility::Hidden
        , ESlateVisibility::Visible
        , ESlateVisibility::Hidden);

    MainUiInstance->SetProgressBarPercent(Percent);


    //complete!
    if (Percent >= 1.0f && !IsFinished)
    {
        IsFinished = true;
        if(CongratulationLevel.IsNull())
        {
            UE_LOG(LogTemp, Error, TEXT("CongratulationLevel is null"));
            return;
        }

        FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this, true);

        FLatentActionInfo LatentInfo;
        UGameplayStatics::OpenLevelBySoftObjectPtr(this, CongratulationLevel);
    }
}

void ATpsPlayer::OnInteractCanceled(const FInputActionInstance& Value)
{
    if (nullptr == KeyProp)
    {
        UE_LOG(LogTemp, Warning, TEXT("Keyprop is nullptr"));
        return;
    }

    if (FMath::IsNearlyZero(InteractionTargetElapsedTime))
    {
        UE_LOG(LogTemp, Error, TEXT("InteractionTargetElapsedTime is zero"));
        return;
    }

    if (IsFinished)
        return;

    MainUiInstance->SetVisibilities(ESlateVisibility::Visible
        , ESlateVisibility::Hidden
        , ESlateVisibility::Hidden);
}

void ATpsPlayer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));

    TObjectPtr<AKeyProp> Key = Cast<AKeyProp>(OtherActor);
    if (nullptr == Key)
    {
        UE_LOG(LogTemp, Warning, TEXT("Current Collision Object is not key"));
        return;
    }

    KeyProp = Key;

    MainUiInstance->SetVisibilities(ESlateVisibility::Visible
        , ESlateVisibility::Hidden
        , ESlateVisibility::Hidden);
}

void ATpsPlayer::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlap End"));

    KeyProp = nullptr;

    MainUiInstance->SetVisibilities(ESlateVisibility::Hidden
        , ESlateVisibility::Hidden
        , ESlateVisibility::Hidden);
}
