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

	// insitlise all props to Nullptr at first
	for (int i = 0; i < MAX_PROPS; i++)
		propArray[i] = nullptr;

	// Creating prop in index of prop array
	propArray[0] = new Prop(screenPtr, Vector2(30, 10), Vector2(8, 3), Prop::PROPTYPE::WALL);
	propArray[1] = new Prop(screenPtr, Vector2(20, 7), Vector2(3, 3), Prop::PROPTYPE::WALL);
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
	
	for (int i = 0; i < MAX_PROPS; i++)
	{
		if (propArray[i] != nullptr)
			propArray[i]->RenderCharacterDisplay();
	}

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
	//Get the player's desired position based on input
	Vector2 desiredPlayerPos = worldPlayerPtr->GetPlayerDesiredPosition();

	//The boolean that checks if player overlapped with a prop
	bool isPlayerOverlappingWithProp = false;
	//An array of all player's body part positions
	Vector2* playerPoints = worldPlayerPtr->GetPlayerPoints(desiredPlayerPos);

	//Loop thru all props
	for (int i = 0; i < MAX_PROPS && !isPlayerOverlappingWithProp; i++)
	{
		if (propArray[i] != nullptr) {
			//Loop thru all player body part positions
			for (int j = 0; j < worldPlayerPtr->PLAYER_POINTS_SIZE; j++)
			{
				//Check if each body part is overlapping with the wall
				if (propArray[i]->IsOverlapping(playerPoints[j])) {
					//If yes, then break and mark player has overlapped
					isPlayerOverlappingWithProp = true;
					break;
				}
			}
		}
	}

	//If no overlap, then player move
	if (!isPlayerOverlappingWithProp)
	{
		worldPlayerPtr->MovePlayer(desiredPlayerPos);
	}
}
