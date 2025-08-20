#pragma once
#include <windows.h>
#include <iostream>
#include "WorldPlayer.h"
#include "Screen.h"
#include "Prop.h"
#include "Interactable.h";
#include "DialogueInteractable.h";
#include "GameState.h"
#include "GameStateBattle.h"
#include "GameStateWorld.h"

class Game
{
private:
	static const int pageRows = 25, pageCols = 80;

	Screen* screenPtr;

	GameState* currentGameState;
	GameStateWorld gameStateWorld;
	GameStateBattle gameStateBattle;

public:
	Game();

	void GameLoop();
	void DisplayWorld();
};

