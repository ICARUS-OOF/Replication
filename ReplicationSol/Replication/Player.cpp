#include "Player.h"
#include <iostream>
#include <conio.h>


Player::Player()
{
	
}

Player::~Player()
{

}

void Player::move()
{
	char UserInput;
	std::cout << "Enter WASD: " << std::endl;
	UserInput = _getch();

	switch (UserInput)
	{
	case 'w':
	case 'W':
		std::cout << "Moving Up" << std::endl;
		position.Sety(position.Gety() - 1);
		break;
	case 's':
	case 'S':
		position.Sety(position.Gety() + 1);
		break;
	case 'a':
	case 'A':
		position.Sety(position.Getx() - 1);
		break;
	case 'd':
	case 'D':
		position.Sety(position.Getx() + 1);
		break;
	default:
		std::cout << "invalid input" << std::endl;
		break;
	}
}
