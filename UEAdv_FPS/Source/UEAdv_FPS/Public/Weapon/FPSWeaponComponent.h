#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "Components/ActorComponent.h"
#include "FPSWeaponComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEADV_FPS_API UFPSWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UFPSWeaponComponent();

    void StartFire();
    void StopFire();

    UFUNCTION(BlueprintCallable,Category="Weapon|Equipment")
    void EquipmentWeapon();
    
protected:
    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
    TSubclassOf<AWeaponBase> DefaultWeaponClass;

    UPROPERTY()
    TObjectPtr<AWeaponBase> ActiveWeapon;
    
    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
    FName WeaponSocketName;
    
    virtual void BeginPlay() override;
};
