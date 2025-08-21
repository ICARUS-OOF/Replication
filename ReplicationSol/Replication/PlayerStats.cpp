#include "PlayerStats.h"

PlayerStats::PlayerStats(int health, int attack, int defence, int baseDamage)
{
	this->health = health;
	this->maxhealth = health;
	this->attack = attack;
	this->defence = defence;
	this->baseDamage = baseDamage;
}

/// <summary>
/// LAW YU HENG
/// 
/// adds to player health and caps it at maxhealth
/// </summary>
/// <param name="amt">The amount to heal player</param>
void PlayerStats::HealPlayer(int amt)
{
	health += amt;
	if (health > maxhealth) {
		health = maxhealth;
	}
}

/// <summary>
/// LAW YU HENG
/// 
/// subtracts damage amount from player health
/// </summary>
/// <param name="amt">damage taken by player</param>
void PlayerStats::DamagePlayer(int amt)
{
	health -= amt;
}

/// <summary>
/// LAW YU HENG
/// 
/// increases player attack stat
/// </summary>
/// <param name="amt">amount of attack to increase</param>
void PlayerStats::AddAttack(int amt)
{
	attack += amt;
}

/// <summary>
/// LAW YU HENG
/// 
/// increases player defence stat
/// </summary>
/// <param name="amt">amount of defence to increase</param>
void PlayerStats::AddDefence(int amt)
{
	defence += amt;
}

int PlayerStats::GetHealth() const
{
	return health;
}

int PlayerStats::GetAttack() const
{
	return attack;
}

int PlayerStats::GetDefence() const
{
	return defence;
}

int PlayerStats::GetMaxHealth() const
{
	return maxhealth;
}

int PlayerStats::GetBaseDamage() const
{
	return baseDamage;
}
