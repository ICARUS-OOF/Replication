#include "WorldPlayer.h"
#include "WorldEntity.h"
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


/// <summary>
/// AHMAD
/// 
/// Gets user input and moves according to supplied position change
/// </summary>
void WorldPlayer::Move()
{
	char UserInput;
	UserInput = _getch();

	switch (UserInput)
	{
	case 'w':
	case 'W':
		position.Sety(position.Gety() - 1);
		break;
	case 's':
	case 'S':
		position.Sety(position.Gety() + 1);
		break;
	case 'a':
	case 'A':
		position.Setx(position.Getx() - 1);
		break;
	case 'd':
	case 'D':
		position.Setx(position.Getx() + 1);
		break;
	default:
		std::cout << "invalid input" << std::endl;
		break;
	}

	//FOR DEBUGGING THE PLAYER POSITION
	std::cout << DEBUG_GETPLAYERPOSITIONSTRING();
}
