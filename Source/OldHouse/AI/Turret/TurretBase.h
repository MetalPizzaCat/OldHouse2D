// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "OldHouse/Weapons/PistolBase.h"
#include "TurretBase.generated.h"

UCLASS()
class OLDHOUSE_API ATurretBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurretBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle ResetAnimTimerHandle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//part that holds gun on the wall
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	UPaperSpriteComponent* TurretBaseSprite;

	//part that shoots
	UPROPERTY(Category = Animation, EditDefaultsOnly, BlueprintReadWrite)
	UPaperFlipbookComponent* TurretGunSprite;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Animations)
	UPaperFlipbook*IdleAnim;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=Animations)
	UPaperFlipbook*ShootingAnim;

	//This weapon is what actually shoots
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category=Weapon)
	APistolBase*Weapon;

	//must be weapon without textures(although it will be hidden)
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category=Weapon)
	TSubclassOf<APistolBase>WeaponClass;

	//Total angle is MaxRotationAngle*2
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = Rotation)
	float MaxRotationAngle = 30;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = Rotation)
	bool bReachedRight = false;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = Rotation)
	float Speed = 10.f;
	

	UFUNCTION(BlueprintCallable)
	virtual void Shoot();

	UFUNCTION(BlueprintCallable)
	void ResetAnimation();

	UFUNCTION(BlueprintPure)
	virtual FRotator GetShootingRotation();
};
