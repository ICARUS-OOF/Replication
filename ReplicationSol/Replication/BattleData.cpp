#include "BattleData.h"

BattleData::BattleData()
{
}

BattleData::BattleData(EnemyData singleEnemy) : BattleData()
{
	this->firstEnemy = &singleEnemy;
	this->secondEnemy = nullptr;
}

BattleData::BattleData(EnemyData firstEnemy, EnemyData secondEnemy) : BattleData()
{
	this->firstEnemy = &firstEnemy;
	this->secondEnemy = &secondEnemy;
}

bool BattleData::IsSingleBattle()
{
	return this->secondEnemy == nullptr;
}
