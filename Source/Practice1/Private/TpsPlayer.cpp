// Fill out your copyright notice in the Description page of Project Settings.


#include "TpsPlayer.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ATpsPlayer::ATpsPlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
	SpringArm->SetupAttachment(this->GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);
	
    InteractCollision->OnComponentBeginOverlap.AddDynamic(this, &ATpsPlayer::OnOverlapBegin);

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATpsPlayer::BeginPlay()
{
	Super::BeginPlay();
	
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
	
	 SubSystem->AddMappingContext(DefaultMappingContext,0);
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
    if(this->CanJump())
    {
        Super::Jump();
    }
}

void ATpsPlayer::OnInteract(const FInputActionValue& Value)
{

}

void ATpsPlayer::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ATpsPlayer::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
}
