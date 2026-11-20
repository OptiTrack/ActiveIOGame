// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetActor.h"
#include "ShooterGuy.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_CAPSTONE_API AShooterGuy : public ATargetActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	void Fire();
	FTimerHandle FireTimerHandler;

public:
	AShooterGuy();

	UPROPERTY(VisibleAnywhere, Category="Behavior")
	float ShootTimer = 3.0f;
};
