// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DodgeballPlayerController.h"
#include "UI/RestartWidget.h"
#include "UI/HUDWidget.h"

void ADodgeballPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (BP_HUDWidget != nullptr)
	{
		HUDWidget = CreateWidget<UHUDWidget>(this, BP_HUDWidget);
	}

	HUDWidget->AddToViewport();
}

void ADodgeballPlayerController::ShowRestartWidget()
{
	if (WBP_RestartWidget != nullptr)
	{
		SetPause(true);
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;

		RestartWidget = CreateWidget<URestartWidget>(this, WBP_RestartWidget);
		RestartWidget->AddToViewport();
	}
}

void ADodgeballPlayerController::HideRestartWidget()
{
	RestartWidget->RemoveFromParent();
	RestartWidget->Destruct();
	SetPause(false);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void ADodgeballPlayerController::UpdateHealthPercent(float HealthPercent)
{
	if (HUDWidget != nullptr)
	{
		HUDWidget->UpdateHealthPercent(HealthPercent);
	}

}