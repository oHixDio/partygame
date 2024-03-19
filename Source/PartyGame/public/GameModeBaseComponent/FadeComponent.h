// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FadeComponent.generated.h"

class UFadeWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARTYGAME_API UFadeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFadeComponent();
	virtual void BeginPlay() override;

	void ChangeLevel();

protected:
	UPROPERTY(EditAnywhere, Category = "GameModeData")
	bool bShouldFadeIn;

	UPROPERTY(EditAnywhere, Category = "GameModeData")
	bool bShoultFadeOut;

	UPROPERTY(EditAnywhere, Category = "GameModeData")
	TSoftObjectPtr<UWorld> LoadLevel;

	UPROPERTY(VisibleAnywhere)
	UFadeWidget* FadeWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UFadeWidget> FadeWidgetClass;
};
