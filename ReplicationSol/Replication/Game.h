#pragma once
#include <windows.h>
#include <iostream>
#include "WorldPlayer.h"
#include "Screen.h"

class Game
{
private:
	static const int pageRows = 25, pageCols = 80;

	WorldPlayer* worldPlayerPtr;
	Screen* screenPtr;

public:
	Game();
	void GameLoop();
	void DisplayWorld();
	void GetInputs();
};

