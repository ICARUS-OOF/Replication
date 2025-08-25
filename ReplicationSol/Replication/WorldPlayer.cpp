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
	delete[] solidPoints;
	delete[] interactivePoints;
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
			targetPosition = Vector2(position.Getx() - 1, position.Gety());
			currentDecision = PLAYERDECISION::MOVE;
			break;
		case 'd':
		case 'D':
			targetPosition = Vector2(position.Getx() + 1, position.Gety());
			currentDecision = PLAYERDECISION::MOVE;
			break;

		case 'f':
		case 'F':
			currentDecision = PLAYERDECISION::RUN_TESTBATTLE;
			break;

		case 'g':
		case 'G':
			currentDecision = PLAYERDECISION::SWAP_PUZZLEROOMS;
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
	delete[] solidPoints;

	solidPoints = new Vector2[PLAYER_POINTS_SIZE];

	solidPoints[0] = playerTargetPivot.AddToVector2(Vector2(0, 0));
	solidPoints[1] = playerTargetPivot.AddToVector2(Vector2(0, -1));
	solidPoints[2] = playerTargetPivot.AddToVector2(Vector2(-1, 0));
	solidPoints[3] = playerTargetPivot.AddToVector2(Vector2(1, 0));
	solidPoints[4] = playerTargetPivot.AddToVector2(Vector2(-1, 1));
	solidPoints[5] = playerTargetPivot.AddToVector2(Vector2(1, 1));

	return solidPoints;
}

Vector2* WorldPlayer::GetInteractivePoints(Vector2 suppliedPosition)
{
	delete[] interactivePoints;

	interactivePoints = new Vector2[INTERACTIVE_POINTS_SIZE];

	interactivePoints[0] = suppliedPosition.AddToVector2(Vector2(0, -2));
	interactivePoints[1] = suppliedPosition.AddToVector2(Vector2(-1, -1));
	interactivePoints[2] = suppliedPosition.AddToVector2(Vector2(-2, -1));
	interactivePoints[3] = suppliedPosition.AddToVector2(Vector2(-2, 0));
	interactivePoints[4] = suppliedPosition.AddToVector2(Vector2(-2, 1));
	interactivePoints[5] = suppliedPosition.AddToVector2(Vector2(-1, -2));
	interactivePoints[6] = suppliedPosition.AddToVector2(Vector2(0, 1));
	interactivePoints[7] = suppliedPosition.AddToVector2(Vector2(1, 2));
	interactivePoints[8] = suppliedPosition.AddToVector2(Vector2(2, 1));
	interactivePoints[9] = suppliedPosition.AddToVector2(Vector2(2, 0));
	interactivePoints[10] = suppliedPosition.AddToVector2(Vector2(2, -1));
	interactivePoints[11] = suppliedPosition.AddToVector2(Vector2(1, -1));
	interactivePoints[12] = suppliedPosition.AddToVector2(Vector2(0, 2));
	interactivePoints[13] = suppliedPosition.AddToVector2(Vector2(-1, 2));
	interactivePoints[14] = suppliedPosition.AddToVector2(Vector2(1, -2));

	return interactivePoints;
}
