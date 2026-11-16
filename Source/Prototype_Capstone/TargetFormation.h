// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.h"
#include "TargetFormationSettings.h"
#include "TargetFormation.generated.h"

UCLASS()
class PROTOTYPE_CAPSTONE_API ATargetFormation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetFormation();
	void InitializeFormation(const FTargetFormationSettings& Settings);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void SpawnNextTarget();

	int32 SpawnedCount = 0;

	FTimerHandle SpawnTimerHandle;

	FTargetFormationSettings FormationSettings;

};
