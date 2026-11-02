// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "InputCoreTypes.h"

// Sets default values
ATargetActor::ATargetActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));

	RootComponent = TargetMesh;

	TargetMesh->SetWorldScale3D(FVector(30.0f, 30.0f, 30.0f));

	TargetMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	TargetMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}


void ATargetActor::BeginPlay() {
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	EndLocation = StartLocation;

	if (bMovesHorizontal != false) {
		EndLocation.Y += 100.0f;
	}
	if (bMovesVertical != false) {
		EndLocation.Z += 75.0f;
	}

}


// Called when the game starts or when spawned
void ATargetActor::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);

	UE_LOG(LogTemp, Warning, TEXT("Target Was Clicked"));


	if (ButtonPressed != EKeys::LeftMouseButton) {
		return;
	}

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	UE_LOG(LogTemp, Warning, TEXT("Target Should Disappear"));
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ATargetActor::RespawnTarget, 5.0f, false);

	
}

 //Called every frame
void ATargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsHidden())
	{
		return;
	}

	if (GetWorldTimerManager().IsTimerActive(ReturnTimerHandle)) {
		return;
	}

	FVector Target = bReturning ? StartLocation : EndLocation;
	SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), Target, DeltaTime, 100.0f));

	if (GetActorLocation().Equals(Target, 1.0f)) {
		GetWorldTimerManager().SetTimer(ReturnTimerHandle, this, &ATargetActor::SwitchDirections, 1.0f, false);
	}
}



void ATargetActor::RespawnTarget() {
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}


void ATargetActor::SwitchDirections() {
	bReturning = !bReturning;
}
