// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "InputCoreTypes.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

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

	TargetMesh->SetGenerateOverlapEvents(true);

	UStaticMesh* LoadedMesh = LoadObject<UStaticMesh>(
		nullptr,
		TEXT("/Game/Target.Target")
	);

	if (LoadedMesh) TargetMesh->SetStaticMesh(LoadedMesh);
	else UE_LOG(LogTemp, Error, TEXT("LoadObject failed to find Target!"));

}


void ATargetActor::BeginPlay() {
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	//legacy
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
/*void ATargetActor::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (ButtonPressed == EKeys::LeftMouseButton) UGameplayStatics::ApplyDamage(this, 1.0f, nullptr, nullptr, nullptr);
	/*Super::NotifyActorOnClicked(ButtonPressed);

	UE_LOG(LogTemp, Warning, TEXT("Target Was Clicked"));


	if (ButtonPressed != EKeys::LeftMouseButton) {
		return;
	}

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	UE_LOG(LogTemp, Warning, TEXT("Target Should Disappear"));
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ATargetActor::RespawnTarget, 5.0f, false);

	
}*/

void ATargetActor::OnShot_Implementation() {
	UGameplayStatics::ApplyDamage(this, 1.0f, nullptr, nullptr, nullptr);
}

 //Called every frame
void ATargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsHidden())
	{
		return;
	}
	if (bInit) {
		float eTime = GetWorld()->GetTimeSeconds() - StartTime;
		float NewY = StartPosition.Y;
		float NewZ = StartPosition.Z;
		FVector NewLocation(StartPosition.X, NewY, NewZ);
		switch (MovementSettings.MovementPattern) {
		case ETargetMovementPattern::HorizontalWave:
			NewY += (MovementSettings.MovementSpeed * eTime) * (MovementSettings.bInvertY ? -1 : 1);
			NewZ += (MovementSettings.SecondaryStrength * FMath::Sin(MovementSettings.SecondaryFrequency * eTime));
			NewLocation = FVector(StartPosition.X, NewY, NewZ);
			break;
		case ETargetMovementPattern::DescendingCurve:
			NewY += (MovementSettings.MovementSpeed * eTime * eTime) * (MovementSettings.bInvertY ? -1 : 1);
			NewZ += -(MovementSettings.SecondaryStrength * eTime);
			NewLocation = FVector(StartPosition.X, NewY, NewZ);
			break;
		case ETargetMovementPattern::Loner:
			const FVector DestinationPosition = StartPosition + MovementSettings.DestinationOffset;
			const float ExitStartTime = MovementSettings.EntranceDuration + MovementSettings.WaitDuration;
			const float TotalDuration = ExitStartTime + MovementSettings.ExitDuration;
			if (eTime < MovementSettings.EntranceDuration) {
				//entrance, stupid dumb piecewise
				const float u = FMath::Clamp(eTime / MovementSettings.EntranceDuration, 0.0f, 1.0f);
				const float eu = (1.0f - FMath::Cos(u * PI)) / 2.0f;
				NewLocation = FMath::Lerp(StartPosition, DestinationPosition, eu);
			}
			else if (eTime < ExitStartTime) NewLocation = DestinationPosition;
			else if (eTime < TotalDuration) {
				const float u = FMath::Clamp((eTime - ExitStartTime) / MovementSettings.ExitDuration, 0.0f, 1.0f);
				const float eu = (1.0f - FMath::Cos(u * PI)) / 2.0f;
				NewLocation = FMath::Lerp(DestinationPosition, StartPosition, eu);
			}
			break;
		}
		
		if (NewY >= MaxY || NewY <= MinY) {
			Destroy();
			return;
		}
		SetActorLocation(NewLocation);
	}
	else {
		//legacy for the targets that were already in the level
		//they dont respawn anymore though
		if (GetWorldTimerManager().IsTimerActive(ReturnTimerHandle)) {
			return;
		}

		FVector Target = bReturning ? StartLocation : EndLocation;
		SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), Target, DeltaTime, 100.0f));

		if (GetActorLocation().Equals(Target, 1.0f)) {
			GetWorldTimerManager().SetTimer(ReturnTimerHandle, this, &ATargetActor::SwitchDirections, 1.0f, false);
		}
	}
}

void ATargetActor::SwitchDirections() {
	bReturning = !bReturning;
}

void ATargetActor::InitializeMovement(FTargetMovementSettings inMSet) {
	MovementSettings = inMSet;
	StartPosition = GetActorLocation();
	StartTime = GetWorld()->GetTimeSeconds();

	bInit = true;
}

float ATargetActor::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
	CurrentHealth -= DamageAmount;
	if (CurrentHealth <= 0.0f) OnDeath();
	return DamageAmount;
}

void ATargetActor::OnDeath() {
	Destroy();
	return;
}

