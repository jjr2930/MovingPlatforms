#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Congratulations.generated.h"

class UCongratulationsWidget;

UCLASS()
class PRACTICE1_API ACongratulations : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
    ACongratulations();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UCongratulationsWidget> CongratulationsWidgetClass;

    TObjectPtr<UCongratulationsWidget> CongratulationsWidgetInstance;	
};
