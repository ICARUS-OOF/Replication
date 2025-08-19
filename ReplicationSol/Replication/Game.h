#pragma once
#include <windows.h>
#include <iostream>
#include "WorldPlayer.h"

class Game
{
private:
	static const int pageRows = 25, pageCols = 80;

	WorldPlayer* worldPlayerPtr;

public:
	Game();
	void GameLoop();
	void DisplayWorld();
	void GetInputs();
};

