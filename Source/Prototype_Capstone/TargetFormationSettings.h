#pragma once

#include "CoreMinimal.h"
#include "TargetActor.h"
#include "TargetFormationSettings.generated.h"

USTRUCT(BlueprintType)
struct PROTOTYPE_CAPSTONE_API FTargetFormationSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = "Formation")
    TSubclassOf<ATargetActor> TargetClass;

    UPROPERTY(EditAnywhere, Category = "Formation")
    int32 TargetCount = 5;

    UPROPERTY(EditAnywhere, Category = "Formation")
    float Interval = 0.8f;

    UPROPERTY(EditAnywhere, Category = "Formation")
    float EstimatedDuration = 9.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    FTargetMovementSettings MovementSettings;

    UPROPERTY(EditAnywhere, Category = "Formation")
    FVector SpawnOffset = FVector::ZeroVector;
};

