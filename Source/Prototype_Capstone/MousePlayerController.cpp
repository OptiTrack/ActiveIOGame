// Fill out your copyright notice in the Description page of Project Settings.


#include "MousePlayerController.h"


void AMousePlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("MOUSE PLAYER CONTROLLER LOADED"));

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	FInputModeGameAndUI InputMode;
	SetInputMode(InputMode);
}

void AMousePlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    if (WasInputKeyJustPressed(EKeys::LeftMouseButton))
    {
        FHitResult Hit;
        GetHitResultUnderCursor(ECC_Visibility, false, Hit);

        if (Hit.bBlockingHit)
        {
            UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *Hit.GetActor()->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("NOTHING HIT"));
        }
    }
}