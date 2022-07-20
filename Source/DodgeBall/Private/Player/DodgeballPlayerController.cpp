// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DodgeballPlayerController.h"
#include "UI/RestartWidget.h"

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
