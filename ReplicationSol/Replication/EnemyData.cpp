#include "EnemyData.h"

EnemyData::EnemyData(int health, int attack, ENEMYTYPE enemyType)
{
	this->health = health;
	this->attack = attack;
	this->enemyType = enemyType;
	this->maxhealth = health;

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

void EnemyData::DamageEnemy(int amt)
{
	health -= amt;
	if (health <= 0)
		health = 0;
}

EnemyData::ENEMYTYPE EnemyData::GetEnemyType()
{
	return enemyType;
}
