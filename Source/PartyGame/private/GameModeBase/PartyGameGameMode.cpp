// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameModeBase/PartyGameGameMode.h"
#include "Character/PartyGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

APartyGameGameMode::APartyGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Template/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
