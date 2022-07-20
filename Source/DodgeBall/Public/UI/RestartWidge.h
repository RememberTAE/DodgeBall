// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RestartWidge.generated.h"

/**
 * 
 */
UCLASS()
class DODGEBALL_API URestartWidge : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget, OptionalWidget = true))
	class UButton* RestartButton;

protected:
	UFUNCTION()
	void OnRestartClicked();

public:
	virtual void NativeOnInitialized() override;
};
