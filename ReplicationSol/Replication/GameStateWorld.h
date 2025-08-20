#pragma once

#include "Interactable.h";
#include "DialogueInteractable.h";
#include "GameState.h"
#include "Prop.h"
#include "WorldPlayer.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"

class GameStateWorld : public GameState
{
private:
	WorldPlayer* worldPlayerPtr;

	static const int MAX_PROPS = 100;
	// An array of prop pointers
	Prop* propArray[MAX_PROPS];

	int propSpawnIndex = 0;

	Interactable* currentInteractable;
	GameData* gameData;

	GAMESTATEVALUE* gameStateValuePtr;

public:
	GameStateWorld(Screen* screenPtr, GAMESTATEVALUE* gameStateValuePtr, GameData* gameData);
	void SpawnProp(Prop* propPtr);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();

	GAMESTATEVALUE GetGameStateValue();
};