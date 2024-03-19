// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase/TitleGameModeBase.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

ATitleGameModeBase::ATitleGameModeBase()
{
}

void ATitleGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(TitleWidgetClass))
	{
		TitleWidget = CreateWidget(GetWorld(), TitleWidgetClass);
		TitleWidget->AddToViewport();
	}
}

void ATitleGameModeBase::StartGame()
{
	if (HomeLevel.IsValid())
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, HomeLevel);
	}
}

void ATitleGameModeBase::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}
