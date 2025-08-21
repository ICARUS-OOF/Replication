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

	Vector2 lastScreenSize;
	Vector2 lastViewportSize;

public:
	Game();
	~Game();

	void GameLoop();
	void DisplayWorld();
	void UpdateGameStateValue();

	Vector2 GetConsoleViewportSize();
};

