// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetSpawner.h"
#include "TargetActor.h"
#include "TargetFormation.h"
#include "Components/SceneComponent.h"

// Sets default values
ATargetSpawner::ATargetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

}

// Called when the game starts or when spawned
void ATargetSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnNextFormation();
}

// Called every frame
void ATargetSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATargetSpawner::SpawnNextFormation() {

	FVector spawnPos = GetActorLocation() + (bFormation ? (bDirectionPosY ? FVector(0.0f, -300.0f, 0.0f) : FVector(0.0f, 300.0f, 0.0f)) : FVector(0.0f, 0.0f, 1200.0f - GetActorLocation().Z));
	ATargetFormation* SpawnedTarget = GetWorld()->SpawnActor<ATargetFormation>(
		TargetFormationClass,
		spawnPos,
		GetActorRotation()
	);
	if (SpawnedTarget) {
		SpawnedTarget->InitializeFormation(
			bFormation ? ETargetMovementPattern::HorizontalWave : ETargetMovementPattern::DescendingCurve,
			TargetClass,
			Interval,
			TargetCount,
			9.0f,
			bFormation ? FormationASpeed : FormationBSpeed,
			bFormation ? FormationASecondaryStrength : FormationBSecondaryStrength,
			2.0,
			bDirectionPosY
		);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Formation spawning failed."));
		return;
	}
	bFormation = !bFormation;
	GetWorldTimerManager().SetTimer(
		FormationTimerHandle,
		this,
		&ATargetSpawner::SpawnNextFormation,
		9.0f,
		false
	);
}

