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
WorldPlayer::WorldPlayer(Screen* screenPtr, Vector2 startPosition)
{
	this->screenPtr = screenPtr;
	this->position = startPosition;
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
WorldPlayer::PLAYERDECISION WorldPlayer::GetPlayerInput()
{
	PLAYERDECISION currentDecision = PLAYERDECISION::NONE;

	do {
		char UserInput;
		UserInput = _getch();

		switch (UserInput)
		{
		case 'w':
		case 'W':
			targetPosition = Vector2(position.Getx(), position.Gety() - 1);
			currentDecision = PLAYERDECISION::MOVE;
			break;
		case 's':
		case 'S':
			targetPosition = Vector2(position.Getx(), position.Gety() + 1);
			currentDecision = PLAYERDECISION::MOVE;
			break;
		case 'a':
		case 'A':
			targetPosition = Vector2(position.Getx() - 2, position.Gety());
			currentDecision = PLAYERDECISION::MOVE;
			break;
		case 'd':
		case 'D':
			targetPosition = Vector2(position.Getx() + 2, position.Gety());
			currentDecision = PLAYERDECISION::MOVE;
			break;

		case ' ':
			currentDecision = PLAYERDECISION::INTERACT;
			break;


		default:
			std::cout << "Invalid input!" << std::endl;
			currentDecision = PLAYERDECISION::NONE;
			break;
		}
	} while (currentDecision == PLAYERDECISION::NONE);

	//FOR DEBUGGING THE PLAYER POSITION
	//std::cout << DEBUG_GETPLAYERPOSITIONSTRING();
	return currentDecision;
}

/// <summary>
/// KAYDEN
/// 
/// Get an array of player body part positions FROM a player target position
/// </summary>
/// <param name="suppliedPosition"></param>
/// <returns></returns>
Vector2* WorldPlayer::GetPlayerPoints(Vector2 playerTargetPivot)
{
	Vector2 points[PLAYER_POINTS_SIZE];

	points[0] = playerTargetPivot.AddToVector2(Vector2(0, 0));
	points[1] = playerTargetPivot.AddToVector2(Vector2(0, -1));
	points[2] = playerTargetPivot.AddToVector2(Vector2(-1, 0));
	points[3] = playerTargetPivot.AddToVector2(Vector2(1, 0));
	points[4] = playerTargetPivot.AddToVector2(Vector2(-1, 1));
	points[5] = playerTargetPivot.AddToVector2(Vector2(1, 1));

	return points;
}
