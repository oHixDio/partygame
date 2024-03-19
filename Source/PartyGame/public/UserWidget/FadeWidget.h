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
	void FadeIn();

	void FadeOut(TSoftObjectPtr<UWorld> Level = nullptr);

protected:
	UPROPERTY(VisibleAnywhere, Category = "GameModeData")
	TSoftObjectPtr<UWorld> LoadLevel;

	UPROPERTY(BlueprintReadWrite)
	FWidgetAnimationDynamicEvent InEndDelegate;

	UPROPERTY(BlueprintReadWrite)
	FWidgetAnimationDynamicEvent OutEndDelegate;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* FadeInAnimation;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* FadeOutAnimation;

	virtual void NativeOnInitialized();

	UFUNCTION()
	void FadeInFinished();

	UFUNCTION()
	void FadeOutFinished();
};
