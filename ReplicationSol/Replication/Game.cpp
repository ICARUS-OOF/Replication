#include "Game.h"

#include "Interactable.h";
#include "DialogueInteractable.h";

#include <windows.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <conio.h>
#include <sstream>
#include <ctime>
#include <cstdlib>



Game::Game() :
	screenPtr(new Screen(80, 25)),
	gameData(new GameData(screenPtr, GAMESTATEVALUE::WORLDSTATE, new PlayerStats(20, 0, 0, 1), screenPtr->GetScreenSize(), screenPtr->GetConsoleViewportSize())),
	gameStateWorld(GameStateWorld(gameData)),
	gameStateBattle(GameStateBattle(gameData))
{
	srand(time(0));

	//hide the cursor
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	UpdateGameStateValue();
}

Game::~Game()
{
	delete screenPtr;
	delete gameData;
}

/// <summary>
/// KAYDEN
/// 
/// The main game loop, clear console and display screen
/// </summary>
void Game::GameLoop()
{
	while (true) {
		currentGameState->Loop();

		if (currentGameState->GetGameStateValue() != gameData->GetGameStateValue()) {
			UpdateGameStateValue();
		}
	}
}


void Game::UpdateGameStateValue()
{
	GameState* targetState;

	switch (gameData->GetGameStateValue())
	{
	case WORLDSTATE:
		targetState = &gameStateWorld;
		break;
	case BATTLESTATE:
		targetState = &gameStateBattle;
		break;
	default:
		targetState = &gameStateWorld;
		break;
	}

	currentGameState = targetState;
	currentGameState->OnStateEnter();
}


