// Fill out your copyright notice in the Description page of Project Settings.

#include "UFPSInputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputTriggers.h"


class UEnhancedInputLocalPlayerSubsystem;

UFPSInputComponent::UFPSInputComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}


void UFPSInputComponent::SetupInput(TObjectPtr<UInputComponent> InputComponent)
{
    Pawn = Cast<APawn>(GetOwner());
    if (!Pawn)
    {
        return;
    }

    PlayerController = Cast<APlayerController>(Pawn->GetController());
    if (!PlayerController)
    {
        return;
    }

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
        PlayerController->GetLocalPlayer());

    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMappingContext, 0);

    UEnhancedInputComponent* IComponent = Cast<UEnhancedInputComponent>(InputComponent);

    //Move
    IComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &UFPSInputComponent::Move);
    IComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &UFPSInputComponent::Look);
}

void UFPSInputComponent::Move(const FInputActionValue& InputValue)
{
    if (!Pawn || !PlayerController) return;

    const FVector2D Value = InputValue.Get<FVector2D>();

    const FRotator MovementRotation(0.0f, PlayerController->GetControlRotation().Yaw, 0.0f);

    if (Value.X != 0.0f)
    {
        const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
        Pawn->AddMovementInput(MovementDirection, Value.X);
    }
    if (Value.Y != 0.0f)
    {
        const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
        Pawn->AddMovementInput(MovementDirection, Value.Y);
    }
}

void UFPSInputComponent::Look(const FInputActionValue& InputValue)
{
    if (!Pawn || !PlayerController) return;
    const FVector2D Value = InputValue.Get<FVector2D>();
    if (Value.X != 0.f)
    {
        Pawn->AddControllerYawInput(Value.X);
    }
    if (Value.Y != 0.f)
    {
        Pawn->AddControllerPitchInput(Value.Y);
    }
}

// Called when the game starts
void UFPSInputComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...
}


// Called every frame
void UFPSInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}
