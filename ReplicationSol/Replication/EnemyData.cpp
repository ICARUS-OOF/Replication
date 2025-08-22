#include "EnemyData.h"
#include <string>

EnemyData::EnemyData(int health, int attack, ENEMYTYPE enemyType, std::string enemyDescription)
{
	this->health = health;
	this->attack = attack;
	this->enemyType = enemyType;
	this->maxhealth = health;
	this->enemyDescription = enemyDescription;
}

int EnemyData::GetHealth()
{
	return health;
}

int EnemyData::GetAttack()
{
	return attack;
}

int EnemyData::GetMaxHealth()
{
	return maxhealth;
}

/// <summary>
/// Returns TRUE if player is dead
/// </summary>
/// <param name="amt"></param>
/// <returns></returns>
bool EnemyData::DamageEnemy(int amt)
{
	health -= amt;
	if (health <= 0) {
		health = 0;
		return true;
	}

	return false;
}

EnemyData::ENEMYTYPE EnemyData::GetEnemyType()
{
	return enemyType;
}

std::string EnemyData::GetEnemyName()
{
	return EnemyTypeToString(enemyType);
}

bool EnemyData::IsDead()
{
	return health <= 0;
}

std::string EnemyData::GetEnemyDescription()
{
	return enemyDescription;
}

std::string EnemyData::EnemyTypeToString(ENEMYTYPE enemyType)
{
	switch (enemyType)
	{
	case EnemyData::MUTANT:
		return "Mutant";
		break;
	case EnemyData::HEALER:
		return "Healer";
		break;
	case EnemyData::GUARD:
		return "Guard";
		break;
	default:
		return "ERROR";
		break;
	}
}

std::string EnemyData::EnemyTypeToAbilityString(ENEMYTYPE enemyType)
{
	switch (enemyType)
	{
	case EnemyData::MUTANT:
		return "Poison";
		break;
	case EnemyData::HEALER:
		return "Recover";
		break;
	case EnemyData::GUARD:
		return "Armour";
		break;
	default:
		return "ERROR";
		break;
	}
}
