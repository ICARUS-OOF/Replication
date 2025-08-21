#include "GameData.h"
#include "GAMESTATEVALUE.h"
#include "Item.h"
#include <vector>
#include <algorithm>

GameData::GameData(Screen* screenPtr, GAMESTATEVALUE gameStateValue, PlayerStats* playerStats)
{
	this->screenPtr = screenPtr;
	this->currentBattleData = nullptr;
	this->gameStateValue = gameStateValue;
	this->playerStats = playerStats;
	this->inventory = std::vector<Item>(0);

	AddItem(Item("Banana", 4, Item::ITEMTYPE::HEALING, 6, "Nutritious. Ingest the potassium. Heals 6 hp."));
	AddItem(Item("Hardening Soda", 4, Item::ITEMTYPE::DEFENCE, 2, "Concrete flavoured soda that somehow hardens your body. Take 2 less damage for 3 turns."));
}

BattleData* GameData::GetCurrentBattleData()
{
	return currentBattleData;
}

void GameData::SetCurrentBattleData(BattleData* currentBattleData)
{
	this->currentBattleData = currentBattleData;
}

PlayerStats* GameData::GetPlayerStats()
{
	return playerStats;
}

void GameData::AddItem(Item item)
{
	inventory.push_back(item);
}

void GameData::RemoveItem(std::string itemName)
{
	auto iterator = std::find_if(inventory.begin(), inventory.end(),
//Capture the item name by value  //Pass by refence  //it check if the item name match
		[itemName](const Item& item) {return item.GetItemName() == itemName;}
	);

	//If iterator did not reach the end (did not find an item of matching name, erase from the vector
	if (iterator != inventory.end()) {
		inventory.erase(iterator);
	}
}

bool GameData::HasItem(std::string itemName)
{
	auto iterator = std::find_if(inventory.begin(), inventory.end(),
		//Capture the item name by value  //Pass by refence  //it check if the item name match
		[itemName](const Item& item) {return item.GetItemName() == itemName;}
	);

	//If iterator did not reach the end (did not find an item of matching name, erase from the vector
	return iterator != inventory.end();
}

std::vector<Item> GameData::GetInventory()
{
	return inventory;
}

Item GameData::GetInventoryItem(int i)
{
	return inventory.at(i);
}

int GameData::GetInventorySize()
{
	return inventory.size();
}

Screen* GameData::GetScreenPtr()
{
	return screenPtr;
}

GAMESTATEVALUE GameData::GetGameStateValue()
{
	return this->gameStateValue;
}

void GameData::SetGameStateValue(GAMESTATEVALUE gameStateValue)
{
	this->gameStateValue = gameStateValue;
}
