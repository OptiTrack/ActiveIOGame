// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class PROTOTYPE_CAPSTONE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BulletMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorOnClicked(FKey) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	float MovementSpeed = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	FVector Velocity = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Bullet")
	float MinX = 100.0f;

};
