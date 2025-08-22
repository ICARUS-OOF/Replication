#pragma once
#include "BattleData.h"
#include "EnemyData.h"
#include "Screen.h"
#include "GAMESTATEVALUE.h"
#include "PlayerStats.h"
#include "Item.h"

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
public:
	GameData(Screen* screenPtr, GAMESTATEVALUE gameStateValue, PlayerStats* playerStats);

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

	void AddGcoins(int amt);
	void RemoveGcoins(int amt);
	bool HasEnoughGcoins(int amt);


	bool RollDice(int percentage);
};

