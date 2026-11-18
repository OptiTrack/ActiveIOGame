// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeGameModeBase.h"
#include "MousePlayerController.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

namespace
{
	// Fixed keys so each message replaces the previous one instead of stacking.
	constexpr uint64 HealthMessageKey = 9101;
	constexpr uint64 GameOverMessageKey = 9102;
}

APrototypeGameModeBase::APrototypeGameModeBase() {
	PlayerControllerClass = AMousePlayerController::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
}

void APrototypeGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	PlayerHealth = MaxPlayerHealth;
	bGameOver = false;
}

void APrototypeGameModeBase::DamagePlayer(float Amount)
{
	if (bGameOver)
	{
		return;
	}

	PlayerHealth = FMath::Max(0.0f, PlayerHealth - Amount);
	UE_LOG(LogTemp, Warning, TEXT("Player took %.1f damage. Health: %.1f / %.1f"), Amount, PlayerHealth, MaxPlayerHealth);

	if (PlayerHealth <= 0.0f)
	{
		GameOver();
	}
}

void APrototypeGameModeBase::GameOver()
{
	bGameOver = true;
	UE_LOG(LogTemp, Warning, TEXT("Game over."));
	GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &APrototypeGameModeBase::RestartGame, RestartDelay, false);
}

void APrototypeGameModeBase::RestartGame()
{
	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}

void APrototypeGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	UpdateHud();
}

void APrototypeGameModeBase::UpdateHud() const
{
	if (!GEngine)
	{
		return;
	}

	const int32 Max = FMath::CeilToInt(MaxPlayerHealth);
	const int32 Current = FMath::CeilToInt(PlayerHealth);
	const FString Bar = FString::ChrN(Current, TEXT('#')) + FString::ChrN(Max - Current, TEXT('-'));

	// Green when healthy, yellow at half, red when nearly dead.
	const float Fraction = MaxPlayerHealth > 0.0f ? PlayerHealth / MaxPlayerHealth : 0.0f;
	const FColor Color = Fraction > 0.5f ? FColor::Green : (Fraction > 0.25f ? FColor::Yellow : FColor::Red);

	GEngine->AddOnScreenDebugMessage(HealthMessageKey, 1.0f, Color,
		FString::Printf(TEXT("HEALTH [%s] %d/%d"), *Bar, Current, Max), true, FVector2D(2.0f, 2.0f));

	if (bGameOver)
	{
		GEngine->AddOnScreenDebugMessage(GameOverMessageKey, 1.0f, FColor::Red,
			TEXT("GAME OVER - restarting..."), true, FVector2D(3.0f, 3.0f));
	}
}
