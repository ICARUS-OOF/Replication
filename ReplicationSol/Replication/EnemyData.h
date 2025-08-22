#pragma once
#include <string>

class EnemyData
{
public:
	enum ENEMYTYPE {
		MUTANT,
		HEALER,
		GUARD
	};

private:
	int health;
	int attack;
	int maxhealth;
	ENEMYTYPE enemyType;
	std::string enemyDescription;

public:
	EnemyData(int health, int attack, ENEMYTYPE enemyType, std::string enemyDescription);

	int GetHealth();
	int GetAttack();
	int GetMaxHealth();
	bool DamageEnemy(int amt);
	ENEMYTYPE GetEnemyType();
	std::string GetEnemyName();
	bool IsDead();
	std::string GetEnemyDescription();
	static std::string EnemyTypeToString(ENEMYTYPE enemyType);
	static std::string EnemyTypeToAbilityString(ENEMYTYPE enemyType);
};

