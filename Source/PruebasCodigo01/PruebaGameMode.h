// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "PruebaGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PRUEBASCODIGO01_API APruebaGameMode : public AGameMode
{
	GENERATED_BODY()
	
		APruebaGameMode(const FObjectInitializer& ObjectInitializer);

		virtual void StartPlay() override;
		
};
