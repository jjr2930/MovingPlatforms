#include "Congratulations.h"
#include "CongratulationsWidget.h"

// Sets default values
ACongratulations::ACongratulations()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACongratulations::BeginPlay()
{
	Super::BeginPlay();

    if (!CongratulationsWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("CongratulationsWidgetClass is not set in the GameMode."));
        return;
    }

    CongratulationsWidgetInstance = CreateWidget<UCongratulationsWidget>(GetWorld(), CongratulationsWidgetClass);
    if (!CongratulationsWidgetInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create CongratulationsWidgetInstance."));
        return;
    }

    CongratulationsWidgetInstance->AddToViewport();


    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

    if (!PlayerController)
    {
        UE_LOG(LogTemp, Error, TEXT("PlayerController is nullptr."));
        return;
    }

    PlayerController->bShowMouseCursor = true;

    FInputModeUIOnly InputMode;
    PlayerController->SetInputMode(InputMode);    	
}