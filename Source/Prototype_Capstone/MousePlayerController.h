// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmmoHUD.h"
#include "GameFramework/PlayerController.h"
#include "MousePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_CAPSTONE_API AMousePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	FTimerHandle AmmoTimerHandle;

	virtual void BeginPlay() override;

	virtual void PlayerTick(float DeltaTime) override;

	void Reload();

	UPROPERTY(VisibleAnywhere, Category="Shooting")
	int32 Ammo = 6;
	
	UPROPERTY(EditAnywhere, Category = "Shooting")
	int32 MaxAmmo = 6;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	float ReloadSpeed = 1.0f;

	bool bReloading = false;

	UAmmoHUD* HUD;

};
