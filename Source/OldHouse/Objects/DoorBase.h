// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "EdGraphSchema_K2.h"
#include "GameFramework/Actor.h"
#include "OldHouse/Interactions.h"
#include  "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "DoorBase.generated.h"

UCLASS()
class OLDHOUSE_API ADoorBase : public AActor,public IInteractions
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category=State)
	bool bOpen = false;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category=State)
	bool bLocked = false;

	//can character use it directly or needs to use button
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category=Interaction)
	bool bCanBeInteractedDirectly = false;

	UFUNCTION(BlueprintCallable)
	virtual void Toggle();
	
	virtual void OnToggle(){}

	virtual bool CanBeToggled(){return true;}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category =Sprite, VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(Category =Collision, VisibleAnywhere, BlueprintReadWrite)
	UBoxComponent* CollisionBox;

	UPROPERTY(Category = Keys, EditAnywhere, BlueprintReadWrite)
	int KeyId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Sound)
	USoundBase* OpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Sound)
	USoundBase* CloseSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Sound)
	USoundBase* UnlockSound;

	void Interact_Implementation(AActor* interactor) override;
};
