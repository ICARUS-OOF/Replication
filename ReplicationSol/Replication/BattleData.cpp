#include "BattleData.h"
#include "Vector2.h"

BattleData::BattleData()
{
}

BattleData::BattleData(EnemyData* singleEnemy, Vector2 playerFleePoint, int AddGcoins) : BattleData()
{
	this->firstEnemy = singleEnemy;
	this->secondEnemy = nullptr;
	this->playerFleePoint = playerFleePoint;
	this->AddGcoins = AddGcoins;
	this->battleEndState = BATTLEEND::NONE;
}

BattleData::BattleData(EnemyData* firstEnemy, EnemyData* secondEnemy, Vector2 playerFleePoint, int AddGcoins) : BattleData()
{
	this->firstEnemy = firstEnemy;
	this->secondEnemy = secondEnemy;
	this->playerFleePoint = playerFleePoint;
	this->battleEndState = BATTLEEND::NONE;
	this->AddGcoins = AddGcoins;
}

EnemyData* BattleData::GetFirstEnemy()
{
	return firstEnemy;
}

EnemyData* BattleData::GetSecondEnemy()
{
	return secondEnemy;
}

bool BattleData::IsSingleBattle()
{
	return this->secondEnemy == nullptr;
}

void BattleData::SetBattleEndState(BATTLEEND targetBattleEndState)
{
	battleEndState = targetBattleEndState;
}

BattleData::BATTLEEND BattleData::GetBattleEndState()
{
	return battleEndState;
}

Vector2 BattleData::GetPlayerFleePoint()
{
	return playerFleePoint;
}
