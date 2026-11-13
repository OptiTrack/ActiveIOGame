// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetSpawner.generated.h"

UCLASS()
class PROTOTYPE_CAPSTONE_API ATargetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetSpawner();

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ATargetActor> TargetClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class ATargetFormation> TargetFormationClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 TargetCount = 5;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float Interval = 0.8f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	bool bDirectionPosY = true;

	UPROPERTY(EditAnywhere, Category = "Horizontal Sine")
	FVector FormationASpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Horizontal Sine")
	float FormationASpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Horizontal Sine")
	float FormationASecondaryStrength = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Descending Curve")
	FVector FormationBSpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Descending Curve")
	float FormationBSpeed = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Descending Curve")
	float FormationBSecondaryStrength = 50.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FTimerHandle FormationTimerHandle;
	void SpawnNextFormation();
	bool bFormation;
};
