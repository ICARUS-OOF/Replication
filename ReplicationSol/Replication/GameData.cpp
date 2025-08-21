#include "GameData.h"
#include "GAMESTATEVALUE.h"

GameData::GameData(Screen* screenPtr, GAMESTATEVALUE gameStateValue, PlayerStats* playerStats)
{
	this->screenPtr = screenPtr;
	this->currentBattleData = nullptr;
	this->gameStateValue = gameStateValue;
	this->playerStats = playerStats;
}

BattleData* GameData::GetCurrentBattleData()
{
	return currentBattleData;
}

void GameData::SetCurrentBattleData(BattleData* currentBattleData)
{
	this->currentBattleData = currentBattleData;
}

PlayerStats* GameData::GetPlayerStats()
{
	return playerStats;
}

Screen* GameData::GetScreenPtr()
{
	return screenPtr;
}

GAMESTATEVALUE GameData::GetGameStateValue()
{
	return this->gameStateValue;
}

void GameData::SetGameStateValue(GAMESTATEVALUE gameStateValue)
{
	this->gameStateValue = gameStateValue;
}
