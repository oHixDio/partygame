// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModeBase/PartyGameGameMode.h"

#include "UserWidget/FadeWidget.h"

#include "Kismet/GameplayStatics.h"

APartyGameGameMode::APartyGameGameMode()
{
	
}

void APartyGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (FadeSystem.bShouldFadeIn)
	{
		if (IsValid(FadeSystem.FadeWidgetClass))
		{
			FadeSystem.FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeSystem.FadeWidgetClass);
			if (FadeSystem.FadeInTime > 0)
			{
				FadeSystem.FadeWidget->AddToViewport(9000);
				FadeSystem.FadeWidget->FadeIn(FadeSystem.FadeInTime);
			}
			else
			{
				FadeSystem.FadeWidget->RemoveFromParent();
			}
		}
	}
}

void APartyGameGameMode::ChangeLevel(TSoftObjectPtr<UWorld> LoadLevel, float FadeTime)
{
	if (FadeSystem.bShouldFadeIn)
	{
		if (IsValid(FadeSystem.FadeWidget))
		{
			FadeSystem.FadeWidget->AddToViewport(9000);
			FadeSystem.FadeWidget->FadeOut(FadeTime);
		}
		else
		{
			if (IsValid(FadeSystem.FadeWidgetClass))
			{
				FadeSystem.FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeSystem.FadeWidgetClass);
				FadeSystem.FadeWidget->AddToViewport(9000);
				FadeSystem.FadeWidget->FadeOut(FadeTime);
			}
		}
		
	}

	if (UKismetSystemLibrary::IsValidSoftObjectReference(LoadLevel))
	{
		GetWorld()->GetTimerManager().ClearTimer(FadeSystem.ChangeLevelTimerHandle);

		if (FadeTime > 0)
		{
			GetWorld()->GetTimerManager().SetTimer
			(
				FadeSystem.ChangeLevelTimerHandle,
				[this, LoadLevel]() {
					UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), LoadLevel);
				},
				FadeTime,
				false
			);
		}
		else
		{
			UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), LoadLevel);
		}
	}
}
