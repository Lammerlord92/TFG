// Fill out your copyright notice in the Description page of Project Settings.

#include "PruebasCodigo01.h"
#include "PruebaGameMode.h"
#include "Engine.h"
#include "PersonajePrueba.h"
#include "MyHUD.h"

APruebaGameMode::APruebaGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DefaultPawnClass = APersonajePrueba::StaticClass();
	HUDClass = AMyHUD::StaticClass();

}


void APruebaGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}



