#include "GameState.h"
#include "Vector2.h"
#include "GameData.h"

void GameState::RenderScreen(bool clearScreen)
{
	RenderBaseObjects();
	RenderBaseUI();
	screenPtr->DisplayScreen(gameData->GetLastScreenSize(), gameData->GetLastViewportSize());
	gameData->UpdateScreenAndViewportSizes(screenPtr->GetScreenSize(), screenPtr->GetConsoleViewportSize());
	
	if (clearScreen)
		ClearScreen();
}

void GameState::ClearScreen()
{
	screenPtr->ClearScreen();
}
