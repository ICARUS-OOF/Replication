#pragma once
#include <string>

class Item
{
public: 
	enum ITEMTYPE {
		ATTACK,
		HEALING,
		DEFENCE
	};

private:
	std::string itemName;
	int cost;

	ITEMTYPE itemType;
	int itemWeight;

	std::string description;

public:
	Item();
	Item(std::string itemName, int cost, ITEMTYPE itemType, int itemWeight, std::string description);

	std::string GetItemName() const;
	int GetCost() const;
	ITEMTYPE GetItemType() const;
	int GetItemWeight() const;
	std::string GetDescription() const;
};

