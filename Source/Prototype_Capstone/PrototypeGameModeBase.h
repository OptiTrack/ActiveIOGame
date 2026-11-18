// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PrototypeGameModeBase.generated.h"

/**
 * Game mode for the prototype. Owns the player's health and the game-over state.
 */
UCLASS()
class PROTOTYPE_CAPSTONE_API APrototypeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	APrototypeGameModeBase();

	virtual void Tick(float DeltaSeconds) override;

	/** Reduces player health. Ignored once the game is over. Triggers game over at zero. */
	void DamagePlayer(float Amount);

	float GetPlayerHealth() const { return PlayerHealth; }
	float GetMaxPlayerHealth() const { return MaxPlayerHealth; }
	bool IsGameOver() const { return bGameOver; }

protected:
	virtual void BeginPlay() override;

	/** Failure condition: shows the game-over message and schedules a level restart. */
	void GameOver();

	/** Reloads the current level, resetting health and all actors. */
	void RestartGame();

	/** Draws the health bar and game-over text on screen. */
	void UpdateHud() const;

	UPROPERTY(EditAnywhere, Category = "Player")
	float MaxPlayerHealth = 5.0f;

	/** Seconds the game-over message is shown before the level restarts. */
	UPROPERTY(EditAnywhere, Category = "Player")
	float RestartDelay = 4.0f;

	float PlayerHealth = 5.0f;
	bool bGameOver = false;
	FTimerHandle RestartTimerHandle;
};
