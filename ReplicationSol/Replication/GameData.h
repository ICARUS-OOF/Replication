#pragma once
#include "BattleData.h"
#include "EnemyData.h"
#include "Screen.h"
#include "GAMESTATEVALUE.h"
#include "PlayerStats.h"

class GameData
{
private:
	Screen* screenPtr;
	GAMESTATEVALUE gameStateValue;
	PlayerStats* playerStats;

	BattleData* currentBattleData;
public:
	GameData(Screen* screenPtr, GAMESTATEVALUE gameStateValue, PlayerStats* playerStats);

	Screen* GetScreenPtr();

	GAMESTATEVALUE GetGameStateValue();
	void SetGameStateValue(GAMESTATEVALUE gameStateValue);

	BattleData* GetCurrentBattleData();
	void SetCurrentBattleData(BattleData* currentBattleData);

	PlayerStats* GetPlayerStats();
};

