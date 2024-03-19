// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FGameCoreData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	FName GameName;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	FText Description;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4), Category = "GameData | Core")
	int32 MaxAttendance = 1;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	bool bCanJoinSPU = true;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	bool bSplitScreen = false;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	bool bShowContdown;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	int32 TimeLimit = 120;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	bool bShowScore = false;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	TSoftObjectPtr<class UTexture2D> Thumbnail;

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	TSoftObjectPtr<UWorld> Level;

};

USTRUCT(BlueprintType)
struct FGameTutorialData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "GameData | Tutorial")
	bool bShowTutorial = false;

	UPROPERTY(EditAnywhere, Category = "GameData | Tutorial")
	FText TutorialText = FText();

	UPROPERTY(EditAnywhere, Category = "GameData | Tutorial")
	TMap<class UInputAction*, FText> InputTutorials;
};

/**
 * 
 */
UCLASS()
class PARTYGAME_API UGameDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "GameData | Core")
	FGameCoreData GameCoreData;

	UPROPERTY(EditAnywhere, Category = "GameData | Tutorial")
	FGameTutorialData GameTutorialData;
};
