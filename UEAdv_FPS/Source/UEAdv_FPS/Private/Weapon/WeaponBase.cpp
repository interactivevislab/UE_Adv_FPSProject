#include "Weapon/WeaponBase.h"
 
AWeaponBase::AWeaponBase()
{
    PrimaryActorTick.bCanEverTick = false;
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
}

void AWeaponBase::StartFire()
{
}

void AWeaponBase::StopFire()
{
}

void AWeaponBase::MakeShot()
{
}

void AWeaponBase::BeginPlay()
{
    Super::BeginPlay();
    
}

