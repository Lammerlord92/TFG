// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class PRUEBASCODIGO01_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
		AMyHUD(const FObjectInitializer& ObjectInitializer);
	
	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	UTexture2D* CrosshairTex;
};
