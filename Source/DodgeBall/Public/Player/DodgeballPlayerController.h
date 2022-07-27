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
	// UPROPERTY를 지정하지 않으면 가비지 컬렉터가 삭제
	// 위젯을 생성하고 화면에 추가하기 위한 참조 저장
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
