// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseWeaponFireMode.generated.h"

/**
 * 
 */
UCLASS()
class UEADV_FPS_API UBaseWeaponFireMode : public UObject
{
    GENERATED_BODY()
public:
    virtual void StartFire();
    virtual void StopFire();
};
