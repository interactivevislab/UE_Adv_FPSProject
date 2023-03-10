// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UFPSInputComponent.generated.h"


struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEADV_FPS_API UFPSInputComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UFPSInputComponent();

    UPROPERTY(EditDefaultsOnly)
    TObjectPtr<UInputMappingContext> InputMappingContext;

    UPROPERTY(EditDefaultsOnly)
    TObjectPtr<UInputAction> MoveAction;
    UPROPERTY(EditDefaultsOnly)
    TObjectPtr<UInputAction> LookAction;

    UPROPERTY()
    APawn* Pawn;
    
    UPROPERTY()
    APlayerController* PlayerController;
    
    void SetupInput(TObjectPtr<UInputComponent> InputComponent);

    void Move(const FInputActionValue& InputValue);
    void Look(const FInputActionValue& InputValue);
    
protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
