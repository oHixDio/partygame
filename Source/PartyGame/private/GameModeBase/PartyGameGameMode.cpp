// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModeBase/PartyGameGameMode.h"
#include "Character/PartyGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "GameModeBaseComponent/FadeComponent.h"

APartyGameGameMode::APartyGameGameMode()
{
	FadeComponent = CreateDefaultSubobject<UFadeComponent>("FadeComp");
}

void APartyGameGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void APartyGameGameMode::ChangeLevel()
{
	FadeComponent->ChangeLevel();
}
