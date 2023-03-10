// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameModeBase.h"

#include "FPSCharacter.h"
#include "FPSPlayerController.h"

AFPSGameModeBase::AFPSGameModeBase()
{
    DefaultPawnClass = AUEAdvCharacter::StaticClass();
    PlayerControllerClass = AFPSPlayerController::StaticClass();
}
