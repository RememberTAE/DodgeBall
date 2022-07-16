// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DODGEBALL_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SightSource;

protected:
	ACharacter* PlayerCharacter;

	// Whether the Enemy character can see the player this frame
	bool bCanSeePlayer = false;
	// Whether the Enemy character can see the player previous fram
	bool bPreviousCanSeePlayer = false;

	FTimerHandle ThrowTimerHandle;
	float ThrowingInterval = 2.f;
	float ThrowingDelay = 0.5f;

	void ThrowDodgeball();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Dodgeball)
	TSubclassOf<class ADodgeballProjectile> DodgeballClass;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	bool LookAtActor(AActor* TargetActor);

	bool CanSeeActor(const AActor* TargetActor) const;

};
