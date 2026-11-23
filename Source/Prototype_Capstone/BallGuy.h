// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetActor.h"
#include "BallGuy.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_CAPSTONE_API ABallGuy : public ATargetActor
{
	GENERATED_BODY()
	
public:
	ABallGuy();

protected:
	virtual void OnDeath() override;
};
