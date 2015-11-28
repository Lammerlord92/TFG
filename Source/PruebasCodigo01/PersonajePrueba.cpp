// Fill out your copyright notice in the Description page of Project Settings.

#include "PruebasCodigo01.h"
#include "PersonajePrueba.h"
#include "Proyectil1.h"

// Sets default values
APersonajePrueba::APersonajePrueba(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	numObjetos = 0;
	// Create a CameraComponent 
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = CapsuleComponent;

	// Position the camera a bit above the eyes
	FirstPersonCameraComponent->RelativeLocation = FVector(-100.0f, 0, 40.0f + BaseEyeHeight);
	// Allow the pawn to control rotation.
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
}

void APersonajePrueba::SetupPlayerInputComponent(UInputComponent* InputComponent)
{	

	// set up gameplay key bindings
	InputComponent->BindAxis("Adelante", this, &APersonajePrueba::MoveForward);
	InputComponent->BindAxis("Derecha", this, &APersonajePrueba::MoveRight);

	InputComponent->BindAxis("MirarLateral", this, &APersonajePrueba::AddControllerYawInput);
	InputComponent->BindAxis("MirarArriba", this, &APersonajePrueba::AddControllerPitchInput);

	InputComponent->BindAction("Saltar", IE_Pressed, this, &APersonajePrueba::OnStartJump);
	InputComponent->BindAction("Saltar", IE_Released, this, &APersonajePrueba::OnStopJump);

	InputComponent->BindAction("Ataque1", IE_Pressed, this, &APersonajePrueba::OnFire);
}

// Called when the game starts or when spawned -- MODIFICADO
void APersonajePrueba::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("¡El personaje funciona!"));
	}
}

void APersonajePrueba::OnStartJump()
{
	bPressedJump = true;
}
void APersonajePrueba::OnStopJump()
{
	bPressedJump = false;
}

// Called every frame
void APersonajePrueba::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void APersonajePrueba::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}


void APersonajePrueba::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void APersonajePrueba::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		// Get the camera transform
		FVector CameraLoc;
		FRotator CameraRot;
		GetActorEyesViewPoint(CameraLoc, CameraRot);
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the camera to find the final muzzle position
		FVector const MuzzleLocation = CameraLoc + FTransform(CameraRot).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRot;
		MuzzleRotation.Pitch += 10.0f;          // skew the aim upwards a bit
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			// spawn the projectile at the muzzle
			AProyectil1* const Projectile = World->SpawnActor<AProyectil1>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// find launch direction
				FVector const LaunchDir = MuzzleRotation.Vector();
				Projectile->InitVelocity(LaunchDir);
			}
		}
	}
}


