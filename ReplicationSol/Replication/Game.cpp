#include "Game.h"

#include <windows.h>
#include <chrono>
#include <iostream>
#include <thread>

Game::Game()
{
	//Junshen

	worldPlayerPtr = new WorldPlayer;
}

void Game::GameLoop()
{
	while (true) {
		DisplayWorld();
		system("cls");
		GetInputs();
		Sleep(1000);
	}
}


//KAYDEN
//Displays the world view on the console
void Game::DisplayWorld()
{
	//Characters to be displayed in the world content
	char chars[pageRows][pageCols]{};
	//Initialize all characters within this array to empty characters
	for (int i = 0; i < pageRows; i++)
		for (int j = 0; j < pageCols; j++)
			chars[i][j] = ' ';

	//---TEST---
	chars[12][40] = 'P';

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
			std::cout << chars[i][j];

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


void Game::GetInputs()
{
	worldPlayerPtr->Move();
}
