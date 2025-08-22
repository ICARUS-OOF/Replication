#pragma once
#include "Item.h"

class ItemUsage
{
private:
	Item item;
	int usageLeft;

public:
	ItemUsage(Item item, int usageLeft);

	Item GetItem();
	int GetUsageLeft();

	void UpdateItemUsage();

	bool IsUsedUp();
};

