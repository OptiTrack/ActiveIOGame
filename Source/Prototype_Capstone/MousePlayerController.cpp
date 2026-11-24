// Fill out your copyright notice in the Description page of Project Settings.


#include "MousePlayerController.h"
#include "Shootable.h"
#include "Blueprint/UserWidget.h"


void AMousePlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("MOUSE PLAYER CONTROLLER LOADED"));

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	FInputModeGameAndUI InputMode;
	SetInputMode(InputMode);

    TSubclassOf<UAmmoHUD> HUDClass = LoadClass<UAmmoHUD>(nullptr, TEXT("/Game/WDB_HUD_TEST.WDB_HUD_TEST_C"));

    if (HUDClass){
        HUD = CreateWidget<UAmmoHUD>(this, HUDClass);
        if (HUD) {
            HUD->AddToViewport();
            HUD->UpdateAmmoText(Ammo);
        }
    }
}

void AMousePlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    if (WasInputKeyJustPressed(EKeys::LeftMouseButton) && Ammo > 0 && !bReloading)
    {
        Ammo--;
        if (HUD) HUD->UpdateAmmoText(Ammo);
        FHitResult Hit;
        GetHitResultUnderCursor(ECC_Visibility, false, Hit);

        /*if (Hit.bBlockingHit)
        { 
            UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *Hit.GetActor()->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("NOTHING HIT"));
        }*/
        if (Hit.bBlockingHit) {
            AActor* HitActor = Hit.GetActor();
            if (HitActor && HitActor->Implements<UShootable>()) {
                IShootable::Execute_OnShot(HitActor);
            }
        }
    }

    if (WasInputKeyJustPressed(EKeys::RightMouseButton)) {
        bReloading = true;
        GetWorldTimerManager().SetTimer(
            AmmoTimerHandle,
            this,
            &AMousePlayerController::Reload,
            ReloadSpeed,
            false
        );
    }
}

void AMousePlayerController::Reload() {
    Ammo = MaxAmmo;
    bReloading = false;
    if (HUD) HUD->UpdateAmmoText(Ammo);
}

