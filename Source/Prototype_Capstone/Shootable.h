#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Shootable.generated.h"

UINTERFACE(MinimalAPI)
class UShootable : public UInterface
{
    GENERATED_BODY()
};

class PROTOTYPE_CAPSTONE_API IShootable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void OnShot();
};