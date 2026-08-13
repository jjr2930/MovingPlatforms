// Fill out your copyright notice in the Description page of Project Settings.


#include "CongratulationsWidget.h"
#include <Kismet/GameplayStatics.h>

FReply UCongratulationsWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);

    return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}
