// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "TargetActor.generated.h"


UCLASS()
class PROTOTYPE_CAPSTONE_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetActor();

protected:
	// Called when the game starts or when spawned
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

};
