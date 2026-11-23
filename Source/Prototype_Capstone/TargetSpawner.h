// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetFormationSettings.h"
#include "TargetSpawner.generated.h"

UCLASS()
class PROTOTYPE_CAPSTONE_API ATargetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetSpawner();

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ATargetFormation> TargetFormationClass;

	UPROPERTY(EditAnywhere, Category = "Formations")
	TArray<FTargetFormationSettings> FormationSequence;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	bool bLoopSequence = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FTimerHandle FormationTimerHandle;
	void SpawnNextFormation();
	int32 FormationIndex = 0;
};
