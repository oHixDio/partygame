// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameModeBase/PartyGameGameMode.h"
#include "InGameGameMode.generated.h"


class UGameDataAsset;

/**
 * 
 */
UCLASS()
class PARTYGAME_API AInGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInGameGameMode();

protected:
	UPROPERTY(EditAnywhere)
	UGameDataAsset* GameData;
	
};
