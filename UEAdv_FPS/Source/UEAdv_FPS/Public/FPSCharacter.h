// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UFPSInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "UEAdv_FPS/FPSWeaponComponent.h"
#include "FPSCharacter.generated.h"

UCLASS()
class UEADV_FPS_API AUEAdvCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUEAdvCharacter();

    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
    UCameraComponent* PlayerCamera;

    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
    UFPSInputComponent* FPSInputComponent;

    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
    UFPSWeaponComponent* WeaponComponent;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
