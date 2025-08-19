#include "WorldPlayer.h"
#include "WorldEntity.h"
#include <iostream>
#include <conio.h>
#include <string>


WorldPlayer::WorldPlayer()
{
	
}

WorldPlayer::~WorldPlayer()
{

}

std::string WorldPlayer::DEBUG_GETPLAYERPOSITIONSTRING()
{
	return std::to_string(position.Getx()) + ", " + std::to_string(position.Gety());
}

char WorldPlayer::GetCharacterDisplay()
{
	return 'p';
}

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

	std::cout << DEBUG_GETPLAYERPOSITIONSTRING();
}
