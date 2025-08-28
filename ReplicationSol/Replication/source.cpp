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
	intro.PlayBootupScreen();
}

int main(void) {
	MaximiseConsole();


	//-------------------------------------
	//-------IF FALSE, CHOICE PROMPT TO ENABLE DEBUG MODE IS ENABLED------
	bool releaseMode = true;
	//------------DO NOT EDIT THESE-------------
	bool debugModeEnabled = true;
	bool willPlayIntro = true;
	//-------------------------------------


	if (!releaseMode) {


		{
			bool validOptionSelected = false;
			char option = ' ';

			std::cout << "Press '1' to enter normal mode" << std::endl;
			std::cout << "Press '2' to enter debug mode" << std::endl;

			do {
				option = _getch();
				if (option == '1')
					validOptionSelected = true;
				else if (option == '2')
					validOptionSelected = true;
			} while (!validOptionSelected);

			if (option == '1')
				debugModeEnabled = false;
			else if (option == '2')
				debugModeEnabled = true;

			system("cls");
		}





		if (!debugModeEnabled)
			willPlayIntro = true;
		else {
			bool validOptionSelected = false;
			char option = ' ';

			std::cout << "Press '1' to play intro" << std::endl;
			std::cout << "Press '2' to skip" << std::endl;

			do {
				option = _getch();
				if (option == '1')
					validOptionSelected = true;
				else if (option == '2')
					validOptionSelected = true;
			} while (!validOptionSelected);

			if (option == '1')
				willPlayIntro = true;
			else if (option == '2')
				willPlayIntro = false;

			system("cls");
		}

	}
	else {
		debugModeEnabled = false;
		willPlayIntro = true;
	}

	if (willPlayIntro)
		PlayIntro();

    Game* game = new Game(debugModeEnabled);


	game->GameLoop();

	delete game;

	return 0;
}