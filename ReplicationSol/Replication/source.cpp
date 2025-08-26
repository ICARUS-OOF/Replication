#include <windows.h>
#include <iostream>
#include <thread>
#include <string>
#include <conio.h>

#include "Game.h"
#include "Intro.h"
#include "AudioHandler.h"
#include "MusicHandler.h"

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





/// <summary>
/// KAYDEN
/// 
/// Maximise console window
/// </summary>
void MaximiseConsole() {
	//Get the "Handle to a Window" (Basically getting a pointer to the window
	HWND hwnd = GetConsoleWindow();
	HWND owner = GetWindow(hwnd, GW_OWNER); //Get the woner of the handler cuz of visual studio security
	if (owner == NULL)
		ShowWindow(hwnd, SW_MAXIMIZE); //If cannot get owner, try maximising using handle
	else
		ShowWindow(owner, SW_MAXIMIZE); //If owner is authorised, maximise using owner
}

void PlayIntro() {
	Intro intro;
	MusicHandler::PlayMusic("01_4999");
	intro.PlayInCut();
}

int main(void) {
	MaximiseConsole();


	//PlayIntro();

    Game* game = new Game();



	game->GameLoop();

	delete game;

	return 0;
}