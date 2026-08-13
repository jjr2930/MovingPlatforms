// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CongratulationsWidget.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE1_API UCongratulationsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;


protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Congratulations|Properties")
    TSoftObjectPtr<UWorld> LevelToLoad;
};
