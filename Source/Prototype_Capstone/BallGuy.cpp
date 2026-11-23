// Fill out your copyright notice in the Description page of Project Settings.


#include "BallGuy.h"
#include "Ball.h"

ABallGuy::ABallGuy() {
	MaxHealth = 3.0f;
	UMaterialInterface* BallGuyMaterial = LoadObject<UMaterialInterface>(
		nullptr,
		TEXT("/Game/Material_001Blue")
	);

	if (BallGuyMaterial)
	{
		TargetMesh->SetMaterial(0, BallGuyMaterial);
	}
}

void ABallGuy::OnDeath() {
	UE_LOG(LogTemp, Warning, TEXT("Oh no, BallGuy is dead!"));
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	ABall* SpawnedBall = GetWorld()->SpawnActor<ABall>(
		ABall::StaticClass(),
		GetActorLocation(),
		GetActorRotation(),
		SpawnParams
	);
	if (SpawnedBall) SpawnedBall->Velocity += FVector(0.0f, FMath::RandRange(-30.0f, 30.0f), 20.0f);
	Destroy();
}