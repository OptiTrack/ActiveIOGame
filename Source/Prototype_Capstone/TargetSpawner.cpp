// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSpawner.h"
#include "TargetActor.h"
#include "TargetFormation.h"
#include "Components/SceneComponent.h"

// Sets default values
ATargetSpawner::ATargetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

}

// Called when the game starts or when spawned
void ATargetSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnNextFormation();
}

void ATargetSpawner::SpawnNextFormation() {

	if (FormationSequence.IsEmpty()) {
		UE_LOG(LogTemp, Warning, TEXT("No formations configured"));
		return;
	}
	const FTargetFormationSettings& CurrentSettings = FormationSequence[FormationIndex];
	FVector spawnPos = GetActorLocation() + CurrentSettings.SpawnOffset;
	ATargetFormation* SpawnedTargetFormation = GetWorld()->SpawnActor<ATargetFormation>(
		TargetFormationClass,
		spawnPos,
		GetActorRotation()
	);
	if (SpawnedTargetFormation) SpawnedTargetFormation->InitializeFormation(CurrentSettings);
	else {
		UE_LOG(LogTemp, Warning, TEXT("Formation spawning failed."));
		return;
	}
	if (!bLoopSequence && FormationIndex+1 == FormationSequence.Num()) return;
	else FormationIndex = (FormationIndex+1) % FormationSequence.Num();
	GetWorldTimerManager().SetTimer(
		FormationTimerHandle,
		this,
		&ATargetSpawner::SpawnNextFormation,
		CurrentSettings.EstimatedDuration,
		false
	);
}

