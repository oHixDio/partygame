// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PartyGameGameMode.generated.h"

class UFadeWidget;


USTRUCT()
struct FFadeSystem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "FadeSystem")
	bool bShouldFadeIn;

	UPROPERTY(EditAnywhere, Category = "FadeSystem", meta = (ClampMin = 0))
	float FadeInTime;

	UPROPERTY(EditAnywhere, Category = "FadeSystem")
	bool bShoultFadeOut;

	UPROPERTY(EditAnywhere, Category = "FadeSystem", meta = (ClampMin = 0))
	float FadeOutTime;

	UPROPERTY(VisibleAnywhere, Category = "FadeSystem")
	UFadeWidget* FadeWidget;

	UPROPERTY(EditAnywhere, Category = "FadeSystem")
	TSubclassOf<UFadeWidget> FadeWidgetClass;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> LoadLevel;

	UPROPERTY()
	FTimerHandle ChangeLevelTimerHandle;
};

UCLASS(minimalapi)
class APartyGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APartyGameGameMode();
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "GameMode | Core")
	void ChangeLevel();

protected:
	UPROPERTY(EditAnywhere, Category = "FadeSystem")
	FFadeSystem FadeSystem;

	
};


// PlayerCreate
/*
UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4))
	int32 NumJoinPlayers = 2;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 1, ClampMax = 4))
	int32 MaxAttendance = 4;

	UPROPERTY(EditAnywhere)
	int32 NumCPUs = 0;

	UPROPERTY(EditAnywhere)
	bool bShouldJoinSPU = true;

	if (MaxAttendance >= NumJoinPlayers)
	{
		int32 NumCreatePlayers = MaxAttendance - (MaxAttendance - NumJoinPlayers);

		for (int32 i = 1; i < NumCreatePlayers; i++)
		{
			UGameplayStatics::CreatePlayer(GetWorld(), i);
		}
		int32 PlayerNum = GetNumPlayers();

		if (bShouldJoinSPU)
		{
			NumCPUs = MaxAttendance - NumJoinPlayers;
		}

		UE_LOG(LogTemp, Warning, TEXT("Player info Attendance:%d player:%d cpu:%d"), MaxAttendance, PlayerNum, NumCPUs);
		for (int32 i = 0; i < PlayerNum; i++)
		{
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), i);
			FString PlayerName = PlayerController->GetActorNameOrLabel();
			UE_LOG(LogTemp, Warning, TEXT("Player name is %s"), *PlayerName);
			int32 PlayerID = PlayerController->GetLocalPlayer()->GetControllerId();
			UE_LOG(LogTemp, Warning, TEXT("Player ID is %d"), PlayerID);
		}
	}
*/
