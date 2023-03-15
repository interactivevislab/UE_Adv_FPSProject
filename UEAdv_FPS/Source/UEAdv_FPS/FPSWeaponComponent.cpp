#include "FPSWeaponComponent.h"

#include "GameFramework/Character.h"


UFPSWeaponComponent::UFPSWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UFPSWeaponComponent::StartFire()
{
}

void UFPSWeaponComponent::StopFire()
{
}

void UFPSWeaponComponent::EquipmentWeapon()
{
    if(!GetWorld()) return;
    if(!IsValid(DefaultWeaponClass)) return;
    
    const ACharacter* Character = Cast<ACharacter>(GetOwner());
    if(!Character) return;
    
    ActiveWeapon = GetWorld()->SpawnActor<AWeaponBase>(DefaultWeaponClass);
    if(!ActiveWeapon) return;

    const FAttachmentTransformRules AttachmentRules = {EAttachmentRule::SnapToTarget, false};
    ActiveWeapon->AttachToComponent(Character->GetMesh(),AttachmentRules,WeaponSocketName);
}

void UFPSWeaponComponent::BeginPlay()
{
    Super::BeginPlay();
    EquipmentWeapon();
}
