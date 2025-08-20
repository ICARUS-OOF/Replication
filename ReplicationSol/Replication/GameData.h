#pragma once
#include "BattleData.h"
#include "EnemyData.h"

class GameData
{
private:
	BattleData* currentBattleData;
public:
	BattleData* GetCurrentBattleData();
	void SetCurrentBattleData(BattleData* currentBattleData);
};

