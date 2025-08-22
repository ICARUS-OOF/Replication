#pragma once
#include "EnemyData.h"
#include "Vector2.h"
class BattleData
{
public:
	enum BATTLEEND {
		NONE,
		WON,
		FLED
	};

private:
	EnemyData* firstEnemy;
	EnemyData* secondEnemy;
	Vector2 playerFleePoint;
	BATTLEEND battleEndState;

	int AddGcoins;

public:
	BattleData();
	BattleData(EnemyData* singleEnemy, Vector2 playerFleePoint, int AddGcoins);
	BattleData(EnemyData* firstEnemy, EnemyData* secondEnemy, Vector2 playerFleePoint, int AddGcoins);

	EnemyData* GetFirstEnemy();
	EnemyData* GetSecondEnemy();

	bool IsSingleBattle();

	void SetBattleEndState(BATTLEEND targetBattleEndState);
	BATTLEEND GetBattleEndState();

	Vector2 GetPlayerFleePoint();
};

