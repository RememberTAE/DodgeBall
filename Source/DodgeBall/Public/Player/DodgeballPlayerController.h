// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DodgeballPlayerController.generated.h"

/**
 *
 */
UCLASS()
class DODGEBALL_API ADodgeballPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	// UPROPERTY�� �������� ������ ������ �÷��Ͱ� ����
	// ������ �����ϰ� ȭ�鿡 �߰��ϱ� ���� ���� ����
	UPROPERTY()
	class URestartWidget* RestartWidget;

	UPROPERTY()
	class UHUDWidget* HUDWidget;

public:
	#pragma region BP_RestartWidget
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartWidget> WBP_RestartWidget;

	void ShowRestartWidget();
	void HideRestartWidget();
	#pragma endregion

	#pragma region BP_HUDWidget;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UHUDWidget> BP_HUDWidget;

	void UpdateHealthPercent(float HealthPercent);
	#pragma endregion

protected:
	virtual void BeginPlay() override;

};
