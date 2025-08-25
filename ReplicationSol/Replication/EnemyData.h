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

	std::string enemySprite;


public:
	EnemyData(int health, int attack, ENEMYTYPE enemyType, std::string enemyDescription, std::string enemySprite);

	int GetHealth();
	int GetAttack();
	int GetMaxHealth();
	bool DamageEnemy(int amt);
	void HealEnemy(int amt);
	ENEMYTYPE GetEnemyType();
	std::string GetEnemyName();
	bool IsDead();
	bool IsAlive();
	std::string GetEnemyDescription();
	static std::string EnemyTypeToString(ENEMYTYPE enemyType);
	static std::string EnemyTypeToAbilityString(ENEMYTYPE enemyType);

	std::string GetEnemySprite();
};

