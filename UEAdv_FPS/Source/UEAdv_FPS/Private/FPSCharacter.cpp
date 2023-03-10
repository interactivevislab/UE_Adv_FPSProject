#include "FPSCharacter.h"

AUEAdvCharacter::AUEAdvCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
    PlayerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
    PlayerCamera->SetupAttachment(GetRootComponent());
    GetMesh()->SetupAttachment(PlayerCamera);

    FPSInputComponent = CreateDefaultSubobject<UFPSInputComponent>("InputComponent");
}

void AUEAdvCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AUEAdvCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUEAdvCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    if(FPSInputComponent)
    {
        FPSInputComponent->SetupInput(PlayerInputComponent);
    }
}

