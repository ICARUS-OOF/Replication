#include "GameState.h"
#include "Vector2.h"
#include "GameData.h"

/// <summary>
/// KAYDEN
/// 
/// CONSTRUCTOR
/// ABSTRACT class for GameStates
/// </summary>
/// <param name="clearScreen"></param>
void GameState::RenderScreen(bool clearScreen)
{
	RenderBaseObjects();
	RenderBaseUI();
	screenPtr->DisplayScreen(gameData->GetLastScreenSize(), gameData->GetLastViewportSize());
	gameData->UpdateScreenAndViewportSizes(screenPtr->GetScreenSize(), screenPtr->GetConsoleViewportSize());
	
	if (clearScreen)
		ClearScreen();
}

/// <summary>
/// KAYDEN
/// 
/// Clears the screen entirely
/// </summary>
void GameState::ClearScreen()
{
	screenPtr->ClearScreen();
}
