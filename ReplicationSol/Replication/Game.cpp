#include "Game.h"

#include <windows.h>
#include <chrono>
#include <iostream>
#include <thread>


Game::Game()
{
	//Create the screen with rows and cols
	screenPtr = new Screen(pageRows, pageCols);
	//Create player
	worldPlayerPtr = new WorldPlayer(screenPtr);
}

/// <summary>
/// KAYDEN
/// 
/// The main game loop, clear console and display screen
/// </summary>
void Game::GameLoop()
{
	while (true) {
		system("cls");
		DisplayWorld();
		GetInputs();
	}
}


//KAYDEN
//Displays the world view on the console
void Game::DisplayWorld()
{
	//Clear the previous screen
	screenPtr->ClearScreen();

	worldPlayerPtr->RenderCharacterDisplay();

	//Top Border
	std::cout << '+';
	for (int i = 0; i < pageCols; i++)
		std::cout << '-';
	std::cout << '+';

	//World Content
	for (int i = 0; i < pageRows; i++)
	{
		//Leave a new line
		std::cout << std::endl;

		//Left Border
		std::cout << '|';

		//Display each character
		for (int j = 0; j < pageCols; j++)
			std::cout << screenPtr->GetChars()[i][j];

		//Right Border
		std::cout << '|';
	}

	//Leave new line
	std::cout << std::endl;

	//Bottom border
	std::cout << '+';
	for (int i = 0; i < pageCols; i++)
		std::cout << '-';
	std::cout << '+';

	std::cout << std::endl;
}

/// <summary>
/// KAYDEN
/// 
/// Gets all inputs from the player
/// </summary>
void Game::GetInputs()
{
	worldPlayerPtr->Move();
}
