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
	ENEMYTYPE enemyType;

public:
	EnemyData(int health, int attack, ENEMYTYPE enemyType);
};

