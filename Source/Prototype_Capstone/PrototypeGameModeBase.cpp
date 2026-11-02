// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeGameModeBase.h"
#include "MousePlayerController.h"

APrototypeGameModeBase::APrototypeGameModeBase() {
	PlayerControllerClass = AMousePlayerController::StaticClass();
}
