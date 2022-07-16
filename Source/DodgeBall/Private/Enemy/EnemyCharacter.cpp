// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SightSource = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SightSource->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LookAtActor(PlayerCharacter);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::LookAtActor(AActor* TargetActor)
{
	if (TargetActor == nullptr)
		return;

	if (CanSeeActor(TargetActor))
	{
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);
		SetActorRotation(LookAtRotation);
	}
}

bool AEnemyCharacter::CanSeeActor(const AActor* TargetActor) const
{
	if (TargetActor == nullptr)
		return false;

	FHitResult Hit;

	//FVector Start = GetActorLocation();
	FVector Start = SightSource->GetComponentLocation();
	FVector End = TargetActor->GetActorLocation();

	//ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel11;
	FCollisionQueryParams QueryParams;

	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(TargetActor);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// For SweepTrace
	//FQuat Rotation = FQuat::Identity;
	//FCollisionShape Shape = FCollisionShape::MakeBox(FVector(20.f, 20.f, 20.f));
	//GetWorld()->SweepSingleByChannel(Hit, Start, End, Rotation, Channel, Shape);

	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}

