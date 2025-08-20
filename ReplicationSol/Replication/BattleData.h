#pragma once
#include "EnemyData.h"
class BattleData
{
private:
	EnemyData* firstEnemy;
	EnemyData* secondEnemy;

public:
	BattleData();
	BattleData(EnemyData singleEnemy);
	BattleData(EnemyData firstEnemy, EnemyData secondEnemy);

	EnemyData* GetFirstEnemy();
	EnemyData* GetSecondEnemy();

	bool IsSingleBattle();
};

