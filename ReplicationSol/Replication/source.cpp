#include <windows.h>
#include <iostream>
#include <thread>
#include <string>

#include "Game.h"

/*
1. ONLY PUT #include <iostream> in CPP FILES
2. IMMEDIATELY FETCH ORIGIN and PULL CHANGES from Github at start of day
3. ONLY 1 PERSON should be working on 1 FILE
*/

/*
-----------------------------------------------------------
MAKING A FUNCTION
-----------------------------------------------------------
//(AUTHOR)
//(DESCRIPTION)
//PARAMETER 1 - DESCRIPTION if have
//PARAMETER 2 - DESCRIPTION if have
void TestFunction.....
-----------------------------------------------------------
For e.g.
//KAYDEN
//This function prints out a character to the console for a number of times
//yourCharacter - The character is print out
//num - Number of times the character is to be printed out
void PrintCharacter(std::string yourCharacter, int num)
{
	for (int i = 0; i < num; i++)
	{
		std::cout << yourCharacter;
	}
}
-----------------------------------------------------------
*/

int main(void) {

    Game* game = new Game();

	game->GameLoop();

	delete game;

	return 0;
}