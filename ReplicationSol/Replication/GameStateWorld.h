#pragma once

#include "Interactable.h";
#include "DialogueInteractable.h";
#include "GameState.h"
#include "Prop.h"
#include "WorldPlayer.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"
#include "BattleData.h"

class GameStateWorld : public GameState
{
private:
	WorldPlayer* worldPlayerPtr;

	static const int MAX_PROPS = 200;
	static const int MAX_BATTLES = 20;
	// An array of prop pointers
	Prop* propArray[MAX_PROPS];

	int propSpawnIndex = 0;
	int battleSetIndex = 0;
	int currentRoomIndex;

	Interactable* currentInteractable;
	GameData* gameData;

	BattleData* battleDataArray[MAX_BATTLES];

public:
	GameStateWorld(GameData* gameData);
	void DOCUMENTATION_DONOTCALL();
	void SetLevelData();
	Prop* SpawnProp(Prop* propPtr);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();

	GAMESTATEVALUE GetGameStateValue();
};