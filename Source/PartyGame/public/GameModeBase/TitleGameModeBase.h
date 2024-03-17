// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TitleGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PARTYGAME_API ATitleGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATitleGameModeBase();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4))
	int32 NumJoinPlayers = 2;
	
	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4))
	int32 MaxAttendance = 4;

	UPROPERTY(EditAnywhere)
	int32 NumCPUs = 0;

	UPROPERTY(EditAnywhere)
	bool bShouldJoinSPU = true;
};
