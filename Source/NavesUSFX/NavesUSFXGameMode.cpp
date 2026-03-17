// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFXGameMode.h"
#include "NavesUSFXPawn.h"

ANavesUSFXGameMode::ANavesUSFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesUSFXPawn::StaticClass();
}

