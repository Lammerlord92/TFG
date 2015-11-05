// Fill out your copyright notice in the Description page of Project Settings.

#include "PruebasCodigo01.h"
#include "Proyectil1.h"


// Sets default values
AProyectil1::AProyectil1(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Use a sphere as a simple collision representation
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);

	CollisionComp->OnComponentHit.AddDynamic(this, &AProyectil1::OnHit);

	CollisionComp->BodyInstance.SetCollisionProfileName("Proyectil1");

	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

}

void AProyectil1::InitVelocity(const FVector& ShootDirection)
{
	if (ProjectileMovement)
	{
		// set the projectile's velocity to the desired direction
		ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
	}
}

// Called when the game starts or when spawned
void AProyectil1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectil1::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProyectil1::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GOLPE"));
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Movimiento"));
		OtherComp->AddImpulseAtLocation(ProjectileMovement->Velocity * 100.0f, Hit.ImpactPoint);
	}
}

