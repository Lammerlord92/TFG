// Fill out your copyright notice in the Description page of Project Settings.


#include "TFGProject.h"
#include "ModoJuego.h"
#include "Engine.h"


AModoJuego::AModoJuego(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AModoJuego::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HELLO WORLD"));
	}
}
