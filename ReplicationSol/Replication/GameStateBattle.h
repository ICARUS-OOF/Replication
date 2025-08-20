#pragma once

#include "GameState.h"
#include "PlayerStats.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"
#include "BattleData.h"

class GameStateBattle : public GameState
{
private:
	PlayerStats* playerStatsPtr;

	GAMESTATEVALUE* gameStateValuePtr;
	GameData* gameData;

	BattleData* currentBattleData;
public:
	GameStateBattle(Screen* screenPtr, PlayerStats* playerStatsPtr, GAMESTATEVALUE* gameStateValuePtr, GameData* gameData);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();
	GAMESTATEVALUE GetGameStateValue();
};

