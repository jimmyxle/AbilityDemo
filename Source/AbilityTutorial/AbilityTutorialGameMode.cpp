// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityTutorialGameMode.h"
#include "AbilityTutorialCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAbilityTutorialGameMode::AAbilityTutorialGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
