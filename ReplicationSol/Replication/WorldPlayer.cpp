#include "WorldPlayer.h"
#include "WorldEntity.h"
#include "Vector2.h"
#include <iostream>
#include <conio.h>
#include <string>

/// <summary>
/// 
/// </summary>
/// <param name="screenPtr"></param>
WorldPlayer::WorldPlayer(Screen* screenPtr)
{
	this->screenPtr = screenPtr;
}

WorldPlayer::~WorldPlayer()
{

}

/// <summary>
/// KAYDEN
/// 
/// FOR DEBUGGING PLAYER POSITION
/// </summary>
/// <returns></returns>
std::string WorldPlayer::DEBUG_GETPLAYERPOSITIONSTRING()
{
	return std::to_string(position.Getx()) + ", " + std::to_string(position.Gety());
}

/// <summary>
/// KAYDEN
/// 
/// Rendering the Character's Design
/// </summary>
void WorldPlayer::RenderCharacterDisplay()
{
	screenPtr->RenderCharacter('|', position.Getx(), position.Gety());
	screenPtr->RenderCharacter('O', position.Getx(), position.Gety() - 1);
	screenPtr->RenderCharacter('/', position.Getx() - 1, position.Gety());
	screenPtr->RenderCharacter('\\', position.Getx() + 1, position.Gety());
	screenPtr->RenderCharacter('/', position.Getx() - 1, position.Gety() + 1);
	screenPtr->RenderCharacter('\\', position.Getx() + 1, position.Gety() + 1);
}


void WorldPlayer::MovePlayer(Vector2 targetPosition)
{
	position = targetPosition;
}

/// <summary>
/// AHMAD
/// 
/// Gets user input and moves according to supplied position change
/// </summary>
Vector2 WorldPlayer::GetPlayerDesiredPosition()
{

	Vector2 targetPosition;
	bool isValidInput = false;

	do {
		char UserInput;
		UserInput = _getch();

		switch (UserInput)
		{
		case 'w':
		case 'W':
			targetPosition = Vector2(position.Getx(), position.Gety() - 1);
			isValidInput = true;
			break;
		case 's':
		case 'S':
			targetPosition = Vector2(position.Getx(), position.Gety() + 1);
			isValidInput = true;
			break;
		case 'a':
		case 'A':
			targetPosition = Vector2(position.Getx() - 1, position.Gety());
			isValidInput = true;
			break;
		case 'd':
		case 'D':
			targetPosition = Vector2(position.Getx() + 1, position.Gety());
			isValidInput = true;
			break;
		default:
			std::cout << "Invalid input!" << std::endl;
			isValidInput = false;
			break;
		}
	} while (!isValidInput);

	//FOR DEBUGGING THE PLAYER POSITION
	//std::cout << DEBUG_GETPLAYERPOSITIONSTRING();

	return targetPosition;
}

Vector2* WorldPlayer::GetPlayerPoints()
{
	Vector2 points[PLAYER_POINTS_SIZE];

	points[0] = Vector2(0, 0);
	points[0] = Vector2(0, 0);
}
