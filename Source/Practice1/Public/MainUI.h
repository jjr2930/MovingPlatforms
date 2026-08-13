// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUI.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE1_API UMainUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="MainUI")
    void SetVisibilities(ESlateVisibility InAlertVisibility
        , ESlateVisibility InProgressBarVisibility
        , ESlateVisibility InCongratulationVisibility);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "MainUI")
    void SetProgressBarPercent(float InPercent);
};
