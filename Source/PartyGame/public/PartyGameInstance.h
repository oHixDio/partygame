// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PartyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PARTYGAME_API UPartyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4), Category = "GameData | Core")
	int32 NumOfJoinPlayers = 1;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	bool bShouldJoinSPU = true;

	
};
