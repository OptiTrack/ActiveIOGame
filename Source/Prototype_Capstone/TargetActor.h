// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "TargetActor.generated.h"

UENUM(BlueprintType)
enum class ETargetMovementPattern : uint8
{
	HorizontalWave UMETA(DisplayName = "Horizontal Wave"),
	DescendingCurve UMETA(DisplayName = "Descending Curve")
};

UCLASS()
class PROTOTYPE_CAPSTONE_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();
	void InitializeMovement(ETargetMovementPattern, float, float, float);

protected:
	// Called when the game starts or when spawned
	//legacy
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

	void RespawnTarget();

	void SwitchDirections();
	FVector StartLocation;
	FVector EndLocation;
	bool bReturning = false;


	UPROPERTY(EditAnywhere, Category= "Target")
	bool bMovesHorizontal = false;
	UPROPERTY(EditAnywhere, Category = "Target")
	bool bMovesVertical = false;

	UStaticMeshComponent* TargetMesh;
	FTimerHandle RespawnTimerHandle;
	FTimerHandle ReturnTimerHandle;
	//end legacy

	float PrimarySpeed = 200.0f;
	float SecondaryStrength = 50.0f;
	float SecondaryFrequency = 2.0f;

	float StartTime = 0.0f;

	FVector StartPosition = FVector::ZeroVector;

	bool bInit = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MinY = -800.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxY = 800.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	ETargetMovementPattern MovementPattern = ETargetMovementPattern::HorizontalWave;

};
