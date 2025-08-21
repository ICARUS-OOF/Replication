#include "Game.h"

#include "Interactable.h";
#include "DialogueInteractable.h";

#include <windows.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <conio.h>
#include <sstream>



Game::Game() :
	screenPtr(new Screen(80, 25)),
	gameData(new GameData(screenPtr, GAMESTATEVALUE::WORLDSTATE, new PlayerStats(20, 0, 0, 9))),
	gameStateWorld(GameStateWorld(gameData)),
	gameStateBattle(GameStateBattle(gameData))
{
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
		DisplayWorld();
		currentGameState->GetInputs();

		if (currentGameState->GetGameStateValue() != gameData->GetGameStateValue()) {
			UpdateGameStateValue();
		}
	}
}

//KAYDEN
//Displays the world view on the console
void Game::DisplayWorld()
{

	//Clear the previous screen
	screenPtr->ClearScreen();

	currentGameState->RenderObjects();
	currentGameState->RenderUI();

	Vector2 screenSize = screenPtr->GetScreenSize();
	int cols = screenSize.Getx();
	int rows = screenSize.Gety();

	/*
	{
		//Top Border
		std::cout << '+';
		for (int i = 0; i < cols; i++)
			std::cout << '-';
		std::cout << '+';

		//World Content
		for (int i = 0; i < rows; i++)
		{
			//Leave a new line
			std::cout << std::endl;

			//Left Border
			std::cout << '|';

			//Display each character
			for (int j = 0; j < cols; j++) {
				if ((int)screenPtr->GetChars()[i][j] != 9) {
					std::cout << screenPtr->GetChars()[i][j];
				}
				else {
					std::cout << ' ';
				}
			}

			//Right Border
			std::cout << '|';
		}

		//Leave new line
		std::cout << std::endl;

		//Bottom border
		std::cout << '+';
		for (int i = 0; i < cols; i++)
			std::cout << '-';
		std::cout << '+';

		std::cout << std::endl;
	}
	*/
	{
		std::stringstream ss;
		//Top Border
		ss << '+';
		for (int i = 0; i < cols; i++)
			ss << '-';
		ss << '+';

		//World Content
		for (int i = 0; i < rows; i++)
		{
			//Leave a new line
			ss << std::endl;

			//Left Border
			ss << '|';

			//Display each character
			for (int j = 0; j < cols; j++) {
				if ((int)screenPtr->GetChars()[i][j] != 9) {
					ss << screenPtr->GetChars()[i][j];
				}
				else {
					ss << ' ';
				}
			}

			//Right Border
			ss << '|';
		}

		//Leave new line
		ss << std::endl;

		//Bottom border
		ss << '+';
		for (int i = 0; i < cols; i++)
			ss << '-';
		ss << '+';

		ss << std::endl;


		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, { 0, 0 });
		std::cout << ss.str();
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
