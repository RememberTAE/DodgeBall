// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RestartWidge.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void URestartWidge::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (RestartButton != nullptr)
	{
		RestartButton->OnClicked.AddDynamic(this, &URestartWidge::OnRestartClicked);
	}
}

void URestartWidge::OnRestartClicked()
{
	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}