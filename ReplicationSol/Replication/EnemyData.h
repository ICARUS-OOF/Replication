#pragma once
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

public:
	EnemyData(int health, int attack, ENEMYTYPE enemyType);

	int GetHealth();
	int GetAttack();
	int GetMaxHealth();
	bool DamageEnemy(int amt);
	ENEMYTYPE GetEnemyType();
	bool IsDead();
};

