// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FadeWidget.generated.h"

/**
 * 
 */
UCLASS()
class PARTYGAME_API UFadeWidget : public UUserWidget
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void FadeIn(float FadeTime = 1.0f);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void FadeOut(float FadeTime = 1.0f);

};
