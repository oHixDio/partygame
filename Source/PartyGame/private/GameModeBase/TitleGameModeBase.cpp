// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase/TitleGameModeBase.h"

#include "Kismet/GameplayStatics.h"

ATitleGameModeBase::ATitleGameModeBase()
{
}

void ATitleGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	
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
	

	
	
}
