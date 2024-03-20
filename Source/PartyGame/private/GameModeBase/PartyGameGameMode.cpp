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

void APartyGameGameMode::ChangeLevel()
{
	if (FadeSystem.bShouldFadeIn)
	{
		if (IsValid(FadeSystem.FadeWidget))
		{
			FadeSystem.FadeWidget->AddToViewport(9000);
			FadeSystem.FadeWidget->FadeOut(FadeSystem.FadeOutTime);
		}
		else
		{
			if (IsValid(FadeSystem.FadeWidgetClass))
			{
				FadeSystem.FadeWidget = CreateWidget<UFadeWidget>(GetWorld(), FadeSystem.FadeWidgetClass);
				FadeSystem.FadeWidget->AddToViewport(9000);
				FadeSystem.FadeWidget->FadeOut(FadeSystem.FadeOutTime);
			}
		}
		
	}

	if (UKismetSystemLibrary::IsValidSoftObjectReference(FadeSystem.LoadLevel))
	{
		GetWorld()->GetTimerManager().ClearTimer(FadeSystem.ChangeLevelTimerHandle);

		if (FadeSystem.FadeOutTime > 0)
		{
			GetWorld()->GetTimerManager().SetTimer
			(
				FadeSystem.ChangeLevelTimerHandle,
				[this]() {
					UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), FadeSystem.LoadLevel);
				},
				FadeSystem.FadeOutTime,
				false
			);
		}
		else
		{
			UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), FadeSystem.LoadLevel);
		}
	}
}
