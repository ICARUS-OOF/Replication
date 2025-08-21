#include "Item.h"
#include <string>

Item::Item()
{
}

Item::Item(std::string itemName, int cost, ITEMTYPE itemType, int itemWeight, std::string description)
{
	this->itemName = itemName;
	this->cost = cost;
	this->itemType = itemType;
	this->itemWeight = itemWeight;
	this->description = description;
}

std::string Item::GetItemName() const
{
	return itemName;
}

int Item::GetCost() const
{
	return cost;
}

Item::ITEMTYPE Item::GetItemType() const
{
	return itemType;
}

int Item::GetItemWeight() const
{
	return itemWeight;
}

std::string Item::GetDescription() const
{
	return description;
}
