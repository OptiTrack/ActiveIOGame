// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmmoHUD.generated.h"

class UTextBlock;

UCLASS()
class PROTOTYPE_CAPSTONE_API UAmmoHUD : public UUserWidget
{
    GENERATED_BODY()

public:
    void UpdateAmmoText(int32 Ammo);

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* AmmoText;
};