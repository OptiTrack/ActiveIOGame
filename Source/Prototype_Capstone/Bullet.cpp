// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PrototypeGameModeBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));

	RootComponent = BulletMesh;

	BulletMesh->SetRelativeScale3D(FVector(0.1f));

	BulletMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	BulletMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	BulletMesh->SetGenerateOverlapEvents(true);

	UStaticMesh* LoadedMesh = LoadObject<UStaticMesh>(
		nullptr,
		TEXT("/Engine/BasicShapes/Sphere.Sphere")
	);

	if (LoadedMesh) BulletMesh->SetStaticMesh(LoadedMesh);

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	if (PC) {
		FVector CameraLocation;
		FRotator CameraRotation;
		PC->GetPlayerViewPoint(CameraLocation, CameraRotation);
		FVector Direction = (CameraLocation - GetActorLocation()).GetSafeNormal();
		Velocity = Direction * MovementSpeed;
	}
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + Velocity * DeltaTime);
	if (GetActorLocation().X < MinX) {
		UE_LOG(LogTemp, Warning, TEXT("Bullet hit the player."));
		if (APrototypeGameModeBase* GameMode = GetWorld()->GetAuthGameMode<APrototypeGameModeBase>())
		{
			GameMode->DamagePlayer(Damage);
		}
		Destroy();
		return;
	}
}

void ABullet::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (ButtonPressed == EKeys::LeftMouseButton) Destroy();
}