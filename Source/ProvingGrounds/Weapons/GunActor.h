// Nor really copyrighted by me, Erling. (but kinda)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunActor.generated.h"

UCLASS()
class PROVINGGROUNDS_API AGunActor : public AActor
{
	GENERATED_BODY()

		/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;
	
public:	
	// Sets default values for this actor's properties
	AGunActor();

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABallProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/** Fires a projectile. */
	void OnFire();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	USkeletalMeshComponent * Mesh;
	
	
};
