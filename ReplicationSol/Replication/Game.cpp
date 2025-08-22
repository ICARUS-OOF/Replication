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
	gameData(new GameData(screenPtr, GAMESTATEVALUE::WORLDSTATE, new PlayerStats(20, 0, 0, 1))),
	gameStateWorld(GameStateWorld(gameData)),
	gameStateBattle(GameStateBattle(gameData)),
	lastScreenSize(screenPtr->GetScreenSize())
{
	srand(time(0));

	//hide the cursor
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	lastViewportSize = GetConsoleViewportSize();

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

	if (!lastScreenSize.IsEqualTo(screenSize))
		system("cls");
	lastScreenSize = screenSize;

	Vector2 currentViewportSize = GetConsoleViewportSize();
	if (!lastViewportSize.IsEqualTo(currentViewportSize))
		system("cls");
	lastViewportSize = currentViewportSize;

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
		//String stream to collate all character data into a single string to print efficiently
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


/// <summary>
/// KAYDEN
/// 
/// Gets the actual console's window viewport size, not the game's
/// </summary>
/// <returns></returns>
Vector2 Game::GetConsoleViewportSize()
{
	//Get standard ouput handler
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Contains info about the console screen
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	//If successful in obtaining the csbi
	if (GetConsoleScreenBufferInfo(hOut, &bufferInfo))
	{
		//Obtain the width and height of window
		int windowWidth = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1; //Difference from left ro right - 1 unit
		int windowHeight = bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1; //Difference from top to bottom - 1 unit

		//Return a vector containing these 2
		return Vector2(windowWidth, windowHeight);
	}

	//If could not obtain buffer Info, return 0,0 failure
	return Vector2(0, 0);
}