// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterGuy.h"
#include "Bullet.h"
#include "TimerManager.h"

AShooterGuy::AShooterGuy() {
	MaxHealth = 1.0f;
	UMaterialInterface* ShooterGuyMaterial = LoadObject<UMaterialInterface>(
		nullptr,
		TEXT("/Game/Material_001Green")
	);

	if (ShooterGuyMaterial)
	{
		TargetMesh->SetMaterial(0, ShooterGuyMaterial);
	}
}

void AShooterGuy::BeginPlay(){
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		FireTimerHandler,
		this,
		&AShooterGuy::Fire,
		ShootTimer,
		true
	);

}

void AShooterGuy::Fire() {
	ABullet* SpawnedBullet = GetWorld()->SpawnActor<ABullet>(
		ABullet::StaticClass(),
		GetActorLocation(),
		GetActorRotation()
	);
	GetWorldTimerManager().ClearTimer(FireTimerHandler);
}