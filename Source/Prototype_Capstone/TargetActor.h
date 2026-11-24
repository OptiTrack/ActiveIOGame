// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Sound/SoundBase.h"
#include "Shootable.h"
#include "TargetActor.generated.h"


UENUM(BlueprintType)
enum class ETargetMovementPattern : uint8
{
	HorizontalWave UMETA(DisplayName = "Horizontal Wave"),
	DescendingCurve UMETA(DisplayName = "Descending Curve"),
	Loner UMETA(DisplayName = "Enter, Wait, Exit")
};

USTRUCT(BlueprintType)
struct PROTOTYPE_CAPSTONE_API FTargetMovementSettings {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Formation")
	ETargetMovementPattern MovementPattern;

	UPROPERTY(EditAnywhere, Category = "Movement|Curves")
	float MovementSpeed = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Movement|Curves")
	float SecondaryStrength = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Movement|Curves")
	float SecondaryFrequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bInvertY = false;

	UPROPERTY(EditAnywhere, Category = "Movement|Enter Wait Exit")
	float EntranceDuration = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement|Enter Wait Exit")
	float WaitDuration = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Movement|Enter Wait Exit")
	float ExitDuration = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement|Enter Wait Exit")
	FVector DestinationOffset = FVector(0.0f, 0.0f, -500.0f);
};

UCLASS()
class PROTOTYPE_CAPSTONE_API ATargetActor : public AActor, public IShootable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();
	void InitializeMovement(FTargetMovementSettings);
	virtual float TakeDamage(
		float DamageAmount,
		FDamageEvent const& DamageEvent,
		AController* EventInstigator,
		AActor* DamageCauser
	) override;

protected:
	// Called when the game starts or when spawned
	//legacy

	void SwitchDirections();
	FVector StartLocation;
	FVector EndLocation;
	bool bReturning = false;


	UPROPERTY(EditAnywhere, Category= "Target")
	bool bMovesHorizontal = false;
	UPROPERTY(EditAnywhere, Category = "Target")
	bool bMovesVertical = false;

	UPROPERTY(EditAnywhere, Category = "Audio")
	USoundBase* KillSound;


	UStaticMeshComponent* TargetMesh;

	FTimerHandle RespawnTimerHandle;
	FTimerHandle ReturnTimerHandle;
	//end legacy

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
	virtual void OnShot_Implementation();
	

	float StartTime = 0.0f;

	FVector StartPosition = FVector::ZeroVector;

	bool bInit = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MinY = -800.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxY = 800.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FTargetMovementSettings MovementSettings;

	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 1.0f;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	float CurrentHealth = 1.0f;

	virtual void OnDeath();

};
