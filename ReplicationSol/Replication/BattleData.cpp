#include "BattleData.h"
#include "Vector2.h"

BattleData::BattleData()
{
}


/// <summary>
/// KAYDEN
/// 
/// Constructor for single enemy battle
/// </summary>
/// <param name="singleEnemy"></param>
/// <param name="playerFleePoint"></param>
/// <param name="AddGcoins"></param>
BattleData::BattleData(EnemyData* singleEnemy, Vector2 playerFleePoint, int AddGcoins) : BattleData()
{
	this->firstEnemy = singleEnemy;
	this->secondEnemy = nullptr;
	this->playerFleePoint = playerFleePoint;
	this->AddGcoins = AddGcoins;
	this->battleEndState = BATTLEEND::NONE;
}

/// <summary>
/// KAYDEN
/// 
/// Constructor for double enemy battle
/// </summary>
/// <param name="firstEnemy"></param>
/// <param name="secondEnemy"></param>
/// <param name="playerFleePoint"></param>
/// <param name="AddGcoins"></param>
BattleData::BattleData(EnemyData* firstEnemy, EnemyData* secondEnemy, Vector2 playerFleePoint, int AddGcoins) : BattleData()
{
	this->firstEnemy = firstEnemy;
	this->secondEnemy = secondEnemy;
	this->playerFleePoint = playerFleePoint;
	this->battleEndState = BATTLEEND::NONE;
	this->AddGcoins = AddGcoins;
}

// get the pointer to the first enemy
EnemyData* BattleData::GetFirstEnemy()
{
	return firstEnemy;
}

// get the pointer to the second enemy
EnemyData* BattleData::GetSecondEnemy()
{
	return secondEnemy;
}

// When the battle is a single battle set the second enemy to nullptr to not display
bool BattleData::IsSingleBattle()
{
	return this->secondEnemy == nullptr;
}

// when the battle is a double battle set the second enemy not a nullptr to display
bool BattleData::IsDoubleBattle()
{
	return this->secondEnemy != nullptr;
}

// set to either None, Won, or fled
void BattleData::SetBattleEndState(BATTLEEND targetBattleEndState)
{
	battleEndState = targetBattleEndState;
}

// Return the targetBattle state from the enum in the battle data class
BattleData::BATTLEEND BattleData::GetBattleEndState()
{
	return battleEndState;
}

// get the player to the battle flee point 
Vector2 BattleData::GetPlayerFleePoint()
{
	return playerFleePoint;
}

//  get the amount of gcoin the player can get after a battle
int BattleData::GetGCoinsReward()
{
	return AddGcoins;
}
