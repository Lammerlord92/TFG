// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/GameMode.h"
#include "ModoJuego.generated.h"

/**
 * 
 */
UCLASS()
class TFGPROJECT_API AModoJuego : public AModoJuego
{
	AModoJuego(const FObjectInitializer& ObjectInitializer);
	GENERATED_BODY()
		virtual void StartPlay() override;
	
	
	
};
