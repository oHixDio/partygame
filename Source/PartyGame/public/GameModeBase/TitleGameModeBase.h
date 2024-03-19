// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameModeBase/PartyGameGameMode.h"
#include "TitleGameModeBase.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class PARTYGAME_API ATitleGameModeBase : public APartyGameGameMode
{
	GENERATED_BODY()

public:
	ATitleGameModeBase();

	virtual void BeginPlay() override;

	void StartGame();
	void ExitGame();

protected:
	

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> HomeLevel;

	UPROPERTY(VisibleAnywhere)
	UUserWidget* TitleWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> TitleWidgetClass;

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
