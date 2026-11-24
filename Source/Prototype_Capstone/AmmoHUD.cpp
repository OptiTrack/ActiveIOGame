
#include "AmmoHUD.h"
#include "Components/TextBlock.h"

void UAmmoHUD::UpdateAmmoText(int32 Ammo)
{
    if (AmmoText)
    {
        AmmoText->SetText(FText::FromString(FString::Printf(TEXT("Ammo: %d"), Ammo)));
    }
}