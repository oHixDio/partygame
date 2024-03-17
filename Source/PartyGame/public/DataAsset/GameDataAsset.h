// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FGameCoreData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FName GameName;

	UPROPERTY(EditAnywhere)
	FText Description;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4))
	int32 MaxAttendance = 1;

	UPROPERTY(EditAnywhere)
	bool bShouldJoinSPU = true;
};

/**
 * 
 */
UCLASS()
class PARTYGAME_API UGameDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FGameCoreData GameCoreData;
	
};
