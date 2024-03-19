// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PartyGameGameMode.generated.h"

class UFadeComponent;

UCLASS(minimalapi)
class APartyGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APartyGameGameMode();
	virtual void BeginPlay() override;

public:
	void ChangeLevel();
protected:
	UPROPERTY(EditAnywhere)
	UFadeComponent* FadeComponent;
};



