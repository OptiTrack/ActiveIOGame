// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "TargetActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	RootComponent = CollisionSphere;
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetupAttachment(RootComponent);
	CollisionSphere->SetSphereRadius(30.0f);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionSphere->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionSphere->SetGenerateOverlapEvents(true);

	BallMesh->SetRelativeScale3D(FVector(0.6f));
	UStaticMesh* LoadedMesh = LoadObject<UStaticMesh>(
		nullptr,
		TEXT("/Engine/BasicShapes/Sphere.Sphere")
	);
	if (LoadedMesh) BallMesh->SetStaticMesh(LoadedMesh);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(
		this,
		&ABall::OnBallOverlap
	);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentPos = GetActorLocation();
	SetActorLocation(CurrentPos + (Velocity * DeltaTime));
	Velocity -= FVector(0.0f, 0.0f, 60.0f) * DeltaTime;

}

void ABall::NotifyActorOnClicked(FKey ButtonPressed) {
	if (ButtonPressed != EKeys::LeftMouseButton) return;
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;
	FHitResult HitResult;
	if (PC->GetHitResultUnderCursor(
		ECC_Visibility,
		false,
		HitResult
	)) {
		FVector HitDirection = (HitResult.ImpactPoint - GetActorLocation());
		HitDirection.X = 0.0f;
		HitDirection.Normalize();
		Velocity = HitDirection * -100.0f;
		Velocity.Z = Velocity.Z * 0.5;
		Velocity.Z += 110.0f;
		Velocity.X = 0.0f;
	}
}

void ABall::OnBallOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	ATargetActor* HitTarget = Cast<ATargetActor>(OtherActor);
	if (OtherActor == GetOwner()) return;
	if (HitTarget) UGameplayStatics::ApplyDamage(HitTarget, 1.0f, nullptr, this, nullptr);
}
