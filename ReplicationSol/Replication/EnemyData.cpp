#include "EnemyData.h"
#include <string>


/// <summary>
/// KAYDEN
/// 
///Constructor that determines the enemy health, attack power and enemy type/// </summary>
/// <param name="health"></param>
/// <param name="attack"></param>
/// <param name="enemyType"></param>
EnemyData::EnemyData(int health, int attack, ENEMYTYPE enemyType)
{
	this->health = health;
	this->attack = attack;
	this->enemyType = enemyType;
	this->maxhealth = health;
	this->enemyDescription = "DESC";
	this->enemySprite = "SPRITE";

	SetAnimations();
}

// get the enemy health
int EnemyData::GetHealth()
{
	return health;
}

// get the enemy base attack amount
int EnemyData::GetAttack()
{
	return attack;
}

// get the max health of the enemy
int EnemyData::GetMaxHealth()
{
	return maxhealth;
}

/// <summary>
/// KAYDEN
/// 
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

/// <summary>
/// KAYDEN
/// 
/// heals the enemy health when the ability is used and set the health to 
/// max health when it go over the max health
/// </summary>
/// <param name="amt"></param>
void EnemyData::HealEnemy(int amt)
{
	health += amt;
	if (health >= maxhealth) {
		health = maxhealth;
	}
}

// Gets the enemy type when being set in game
EnemyData::ENEMYTYPE EnemyData::GetEnemyType()
{
	return enemyType;
}

// Gets the enemy name from the enemyType which have been define in the enum in enemy data
std::string EnemyData::GetEnemyName()
{
	return EnemyTypeToString(enemyType);
}

// Tell the enemy if their health is less then 0 then IsDead
bool EnemyData::IsDead()
{
	return health <= 0;
}

// Tells the enemy if their health is more then 0 then IsAlive
bool EnemyData::IsAlive()
{
	return health > 0;
}

// Reset the health to max health when player flee from the enemy
void EnemyData::ResetEnemyHealth()
{
	health = maxhealth;
}

// OBSOLETE
std::string EnemyData::GetEnemyDescription()
{
	return enemyDescription;
}

/// <summary>
/// KAYDEN
/// 
/// Returns the name of the enemy by reading from the enemy type
/// </summary>
/// <param name="enemyType"></param>
/// <returns></returns>
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
	case EnemyData::BOSS:
		return "Nikolai";
		break;
	default:
		return "ERROR";
		break;
	}
}


/// <summary>
/// KAYDEN 
/// 
/// Determine the Enemy ability from the different enemy type
/// </summary>
/// <param name="enemyType"></param>
/// <returns></returns>
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

