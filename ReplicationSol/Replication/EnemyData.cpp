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

bool EnemyData::IsDead()
{
	return health <= 0;
}

std::string EnemyData::GetEnemyDescription()
{
	return enemyDescription;
}
