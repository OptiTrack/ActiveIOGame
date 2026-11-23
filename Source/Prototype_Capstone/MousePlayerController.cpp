// Fill out your copyright notice in the Description page of Project Settings.


#include "MousePlayerController.h"
#include "Kismet/GameplayStatics.h"

void AMousePlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("MOUSE PLAYER CONTROLLER Started"));

    LaserSound = LoadObject<USoundBase>(
        nullptr, TEXT("/Game/Audio/soundza-small-laser-3.soundza-small-laser-3")
    );

    BGMusic = LoadObject<USoundBase>(
        nullptr, TEXT("/Game/Audio/freesound_community-chill-drum-loop-6887.freesound_community-chill-drum-loop-6887")
    );

    if (BGMusic) {
        UGameplayStatics::PlaySound2D(this, BGMusic, 0.5f, 1.0f);
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Background audio not loaded"));
    }
    
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
        if (LaserSound) {
            UGameplayStatics::PlaySound2D(this, LaserSound);
        }
       
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