#pragma once
#include "BattleData.h"
#include "EnemyData.h"
#include "Screen.h"
#include "GAMESTATEVALUE.h"
#include "PlayerStats.h"
#include "Item.h"
#include "Vector2.h"

#include <vector>

class GameData
{
private:
	Screen* screenPtr;
	GAMESTATEVALUE gameStateValue;
	PlayerStats* playerStats;

	BattleData* currentBattleData;

	std::vector<Item> inventory;
	std::vector<EnemyData::ENEMYTYPE> enemyAbilitiesCopied;

	int gcoins;



	Vector2 lastScreenSize;
	Vector2 lastViewportSize;
public:
	GameData(Screen* screenPtr, GAMESTATEVALUE gameStateValue, PlayerStats* playerStats, Vector2 startingScreenSize, Vector2 startingViewportSize);

	Screen* GetScreenPtr();

	GAMESTATEVALUE GetGameStateValue();
	void SetGameStateValue(GAMESTATEVALUE gameStateValue);

	BattleData* GetCurrentBattleData();
	void SetCurrentBattleData(BattleData* currentBattleData);

	PlayerStats* GetPlayerStats();

	void AddItem(Item item);
	void RemoveItem(std::string itemName);
	bool HasItem(std::string itemName);
	std::vector<Item> GetInventory();
	Item GetInventoryItem(int i);
	int GetInventorySize();

	void AddAbility(EnemyData::ENEMYTYPE ability);
	std::vector<EnemyData::ENEMYTYPE> GetAbilities();
	bool HasAbility(EnemyData::ENEMYTYPE targetType);

	void AddGcoins(int amt);
	void RemoveGcoins(int amt);
	bool HasEnoughGcoins(int amt);
	int GetGCoins();


	bool RollDice(int percentage);

	void UpdateScreenAndViewportSizes(Vector2 lastScreenSize, Vector2 lastViewportSize);
	Vector2 GetLastScreenSize() const;
	Vector2 GetLastViewportSize() const;
};

