// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PersonajePrueba.generated.h"

UCLASS(Blueprintable)
class PRUEBASCODIGO01_API APersonajePrueba : public ACharacter
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

	protected:
		virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

public:
	// Sets default values for this character's properties
	APersonajePrueba();
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//handles moving forward/backward
	UFUNCTION()
		void MoveForward(float Val);
	//handles strafing
	UFUNCTION()
		void MoveRight(float Val);

	//sets jump flag when key is pressed
	UFUNCTION()
		void OnStartJump();
	//clears jump flag when key is released
	UFUNCTION()
		void OnStopJump();
	

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FirstPersonCameraComponent;

	// Constructor for AFPSCharacter
	APersonajePrueba(const FObjectInitializer& ObjectInitializer);

	//handles firing
	UFUNCTION()
		void OnFire();

	/** Gun muzzle's offset from the camera location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AProyectil1> ProjectileClass;

	//Objeto coleccionable
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Contadores)
		int32 numObjetos;
};
