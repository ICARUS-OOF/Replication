#include "GameData.h"
#include "GAMESTATEVALUE.h"
#include "EnemyData.h"
#include "Item.h"
#include "Vector2.h"
#include <vector>
#include <algorithm>
#include <cstdlib>

GameData* GameData::SINGLETON = nullptr;

/// <summary>
/// KAYDEN
/// 
/// Constructor for GameData
/// Prob the most useful file in the entire game
/// Passes around necessary information for classes to access  such as the:
/// player inventory, player stats, gcoins and screen pointer
/// </summary>
/// <param name="screenPtr"></param>
/// <param name="gameStateValue"></param>
/// <param name="playerStats"></param>
/// <param name="startingScreenSize"></param>
/// <param name="startingViewportSize"></param>
GameData::GameData(Screen* screenPtr, GAMESTATEVALUE gameStateValue, PlayerStats* playerStats, Vector2 startingScreenSize, Vector2 startingViewportSize, bool debugModeEnabled)
{
	this->SINGLETON = this;
	this->screenPtr = screenPtr;
	this->currentBattleData = nullptr;
	this->gameStateValue = gameStateValue;
	this->playerStats = playerStats;
	this->inventory = std::vector<Item>(0);
	this->enemyAbilitiesCopied = std::vector<EnemyData::ENEMYTYPE>(0);
	this->gcoins = 0;
	this->lastScreenSize = startingScreenSize;
	this->lastViewportSize = startingViewportSize;
	this->debugModeEnabled = debugModeEnabled;

	if (debugModeEnabled)
	{
		// Player attack boost items
		AddItem(Item("Metal Bar", 0, Item::ITEMTYPE::ATTACK, 3, 5, "A rusty metal bar. Could be useful in a fight. Increases attack by 3 for 5 turns"));
		AddItem(Item("Pistol", 0, Item::ITEMTYPE::ATTACK, 4, 4, "A sleek, silver pistol. Doesn’t have much ammo left. Increases attack by 4 for 4 turns."));
		AddItem(Item("Energy Blaster", 20, Item::ITEMTYPE::ATTACK, 8, 3, "Powerful looking piece of technology. It's even rechargeable! Too bad you don't have a charging cable… Increases attack by 8 for 3 turns."));

		// Player Heal items
		AddItem(Item("Banana", 4, Item::ITEMTYPE::HEALING, 6, 0, "Nutritious. Ingest the potassium. Heals 6 hp."));
		AddItem(Item("Slop", 0, Item::ITEMTYPE::HEALING, 2, 0, "Unappetising food. Still edible, though. Heals 2 hp."));
		AddItem(Item("First Aid Kit", 6, Item::ITEMTYPE::HEALING, 10, 0,"A First Aid Kit. Only the bandage and antiseptic spray is left inside. Heals 10 hp."));
		AddItem(Item("Pocket watch", 20, Item::ITEMTYPE::HEALING, 20, 0, "Upon closer look, this unassuming pocket watch reverses the state of your body, bringing you back to being healthy. Heals you to maximum hp."));

		// Player Defence items
		AddItem(Item("Hardening Soda", 4, Item::ITEMTYPE::DEFENCE, 2, 3, "Concrete flavoured soda that somehow hardens your body. Take 2 less damage for 3 turns."));
		AddItem(Item("Riot Shield", 6, Item::ITEMTYPE::DEFENCE, 4, 2, "Shield. Might not be strong enough against your enemies. Take 4 less damage for 2 turns."));
		AddItem(Item("Portable Barrier", 20, Item::ITEMTYPE::DEFENCE, 8, 3, "A small device that materialises a barrier. It can't block all attacks though. Take 8 less damage for 3 turns"));
	}
}

GameData::~GameData()
{
	delete playerStats;
}

//Getter for last battleData that was set
BattleData* GameData::GetCurrentBattleData()
{
	return currentBattleData;
}

//Setter for last battleData
void GameData::SetCurrentBattleData(BattleData* currentBattleData)
{
	this->currentBattleData = currentBattleData;
}

//Getter for player stats
PlayerStats* GameData::GetPlayerStats()
{
	return playerStats;
}

//Function to directly add an item to the inventory
void GameData::AddItem(Item item)
{
	inventory.push_back(item);
}

//Remove the item using that stupid iterator
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

//Returns if inventory contains an item of matching name
bool GameData::HasItem(std::string itemName)
{
	auto iterator = std::find_if(inventory.begin(), inventory.end(),
		//Capture the item name by value  //Pass by refence  //it check if the item name match
		[itemName](const Item& item) {return item.GetItemName() == itemName;}
	);

	//If iterator did not reach the end (did not find an item of matching name, erase from the vector
	return iterator != inventory.end();
}

//Getter for inventory vector of items
std::vector<Item> GameData::GetInventory()
{
	return inventory;
}

//Getter for an item at index "i"
Item GameData::GetInventoryItem(int i)
{
	return inventory.at(i);
}

//Getter for the number of items in the inventory
int GameData::GetInventorySize()
{
	return inventory.size();
}


/// <summary>
/// KAYDEN
/// 
/// Adds an ability to the abilities vector
/// </summary>
/// <param name="ability"></param>
void GameData::AddAbility(EnemyData::ENEMYTYPE ability)
{
	//If ability is to be pushed to the vector, this is set to true
	bool add = true;
	for (int i = 0; i < enemyAbilitiesCopied.size(); i++)
	{
		//If ability was already unlocked, then do not add
		if (enemyAbilitiesCopied[i] == ability) {
			add = false;
			break;
		}
	}

	//If add was true, then push to vector
	if (add) {
		enemyAbilitiesCopied.push_back(ability);
	}
}

//Getter for abilities
std::vector<EnemyData::ENEMYTYPE> GameData::GetAbilities()
{
	return enemyAbilitiesCopied;
}

//Checks if player already has ability
bool GameData::HasAbility(EnemyData::ENEMYTYPE targetType)
{
	for (int i = 0; i < enemyAbilitiesCopied.size(); i++)
	{
		//If ability already unlocked, return true
		if (targetType == enemyAbilitiesCopied[i])
			return true;
	}

	return false;
}

/// <summary>
/// YU HENG
/// 
/// Adds GCoins
/// </summary>
/// <param name="amt"></param>
void GameData::AddGcoins(int amt)
{
	gcoins += amt;
}

/// <summary>
/// YU HENG
/// 
/// Removes GCoins
/// </summary>
/// <param name="amt"></param>
void GameData::RemoveGcoins(int amt)
{
	gcoins -= amt;

	//Cap at 0 GCoins
	if (gcoins < 0) {
		gcoins = 0;
	}
}

/// <summary>
/// YU HENG
/// 
/// Checks if gcoins is sufficient for "amt"
/// </summary>
/// <param name="amt"></param>
/// <returns></returns>
bool GameData::HasEnoughGcoins(int amt)
{
	return gcoins >= amt;
}

//Getter for GCoins
int GameData::GetGCoins()
{
	return gcoins;
}

/// <summary>
/// "percentage" chance of being true
/// </summary>
/// <param name="percentage"></param>
/// <returns></returns>
bool GameData::RollDice(int percentage)
{
	int num = rand() % 101;
	return num <= percentage;
}

//Getter for the last screenPtr rows and cols sizes
Vector2 GameData::GetLastScreenSize() const
{
	return lastScreenSize;
}

//Getter for the last entire viewport size
Vector2 GameData::GetLastViewportSize() const
{
	return lastViewportSize;
}

bool GameData::IsDebugModeEnabled()
{
	return debugModeEnabled;
}

GameData* GameData::GetSingleton()
{
	return SINGLETON;
}

//Align the screen and viewport sizes to latest sizes
void GameData::UpdateScreenAndViewportSizes(Vector2 lastScreenSize, Vector2 lastViewportSize)
{
	this->lastScreenSize = lastScreenSize;
	this->lastViewportSize = lastViewportSize;
}

//Return a pointer to the screen
Screen* GameData::GetScreenPtr()
{
	return screenPtr;
}

//Getter for the current game state in enum form
GAMESTATEVALUE GameData::GetGameStateValue()
{
	return this->gameStateValue;
}

//Directly transitions game state
void GameData::SetGameStateValue(GAMESTATEVALUE gameStateValue)
{
	this->gameStateValue = gameStateValue;
}
