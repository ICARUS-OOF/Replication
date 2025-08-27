#include "Item.h"
#include <string>

Item::Item()
{
}

/// <summary>
/// AHMAD
/// 
/// Constructor which INSITIALISE variables
/// </summary>
/// <param name="itemName"></param>
/// <param name="cost"></param>
/// <param name="itemType"></param>
/// <param name="itemWeight"></param>
/// <param name="turnUsage"></param>
/// <param name="description"></param>
Item::Item(std::string itemName, int cost, ITEMTYPE itemType, int itemWeight, int turnUsage, std::string description)
{
	this->itemName = itemName;
	this->cost = cost;
	this->itemType = itemType;
	this->itemWeight = itemWeight;
	this->turnUsage = turnUsage;
	this->description = description;
}

// Get the set item name and returns it
std::string Item::GetItemName() const
{
	return itemName;
}

// Get the set item cost and returns it
int Item::GetCost() const
{
	return cost;
}

// Get the set item type and returns it
Item::ITEMTYPE Item::GetItemType() const
{
	return itemType;
}

// Get the set item weight which is the item effect and returns it
int Item::GetItemWeight() const
{
	return itemWeight;
}

// Get the item set description and returns it
std::string Item::GetDescription() const
{
	return description;
}

// Get the set item Effect usage left and returns it
int Item::GetUsesLeft() const
{
	return turnUsage;
}
