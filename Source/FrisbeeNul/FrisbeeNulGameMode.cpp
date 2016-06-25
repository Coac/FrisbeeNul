// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "FrisbeeNul.h"
#include "FrisbeeNulGameMode.h"
#include "FrisbeeNulPlayerController.h"
#include "FrisbeeNulCharacter.h"

AFrisbeeNulGameMode::AFrisbeeNulGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AFrisbeeNulPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}