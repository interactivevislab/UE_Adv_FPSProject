// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS(Abstract)
class UEADV_FPS_API AWeaponBase : public AActor
{
    GENERATED_BODY()

public:
    AWeaponBase();

    virtual void StartFire();
    virtual void StopFire();
    
    virtual void MakeShot();
    
protected:
    virtual void BeginPlay() override;
    
    UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
    TObjectPtr<USkeletalMeshComponent> WeaponMesh;
};
