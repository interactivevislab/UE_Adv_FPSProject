// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseWeaponShootingType.generated.h"
/**
 * 
 */
UCLASS()
class UEADV_FPS_API UBaseWeaponShootingType : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION()
    virtual void MakeShot();
};
