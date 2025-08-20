#include "GameData.h"

BattleData* GameData::GetCurrentBattleData()
{
	return currentBattleData;
}

void GameData::SetCurrentBattleData(BattleData* currentBattleData)
{
	this->currentBattleData = currentBattleData;
}
