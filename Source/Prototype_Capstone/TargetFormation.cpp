// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetFormation.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ATargetFormation::ATargetFormation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

}

// Called when the game starts or when spawned
void ATargetFormation::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATargetFormation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATargetFormation::SpawnNextTarget() {
	if (SpawnedCount >= FormationSettings.TargetCount) {
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
		Destroy();
		return;
	}

	ATargetActor* NewTarget = GetWorld()->SpawnActor<ATargetActor>(
		FormationSettings.TargetClass,
		GetActorLocation(),
		GetActorRotation()
	);

	if (NewTarget) {
		NewTarget->InitializeMovement(FormationSettings.MovementPattern, FormationSettings.bInvertY ? -FormationSettings.MovementSpeed : FormationSettings.MovementSpeed, FormationSettings.SecondaryStrength, FormationSettings.SecondaryFrequency);
		SpawnedCount++;
		UE_LOG(LogTemp, Log, TEXT("Formation spawned target %d"), SpawnedCount);
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("Failed to spawn target"));
		GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
	}
}

void ATargetFormation::InitializeFormation(const FTargetFormationSettings& Settings) {
	FormationSettings = Settings;

	if (!FormationSettings.TargetClass || FormationSettings.TargetCount <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("Settings for formation not set"));
		return;
	};

	SpawnNextTarget();

	if (SpawnedCount < FormationSettings.TargetCount) {
		GetWorldTimerManager().SetTimer(
			SpawnTimerHandle,
			this,
			&ATargetFormation::SpawnNextTarget,
			FormationSettings.Interval,
			true
		);
	}
}

