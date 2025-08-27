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
#include "GameStateEnd.h"
#include "PlayerStats.h"
#include "GameData.h"
#include "GAMESTATEVALUE.h"

class Game
{
private:
	Screen* screenPtr;

	GameData* gameData;

	GameState* currentGameState;
	GameStateWorld gameStateWorld;
	GameStateBattle gameStateBattle;
	GameStateEnd gameStateEnd;

	bool debugModeEnabled;

public:
	Game(bool debugModeEnabled);
	~Game();

	void GameLoop();
	void UpdateGameStateValue();
};

