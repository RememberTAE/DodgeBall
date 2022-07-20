// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/DodgeballFunctionLibrary.h"

#include "DrawDebugHelpers.h"

bool UDodgeballFunctionLibrary::CanSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor, TArray<const AActor*> IgnoreActors)
{
	if (TargetActor == nullptr)
		return false;

	FHitResult Hit;

	FVector Start = Location;
	FVector End = TargetActor->GetActorLocation();

	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;
	FCollisionQueryParams QueryParams;

	QueryParams.AddIgnoredActors(IgnoreActors);
	QueryParams.AddIgnoredActor(TargetActor);

	World->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// For SweepTrace
	//FQuat Rotation = FQuat::Identity;
	//FCollisionShape Shape = FCollisionShape::MakeBox(FVector(20.f, 20.f, 20.f));
	//GetWorld()->SweepSingleByChannel(Hit, Start, End, Rotation, Channel, Shape);

	DrawDebugLine(World, Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
