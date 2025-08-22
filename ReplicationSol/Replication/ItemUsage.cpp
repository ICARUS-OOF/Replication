#include "ItemUsage.h"
#include "Item.h"

ItemUsage::ItemUsage(Item item, int usageLeft)
{
	this->item = item;
	this->usageLeft = usageLeft + 1;
}

Item ItemUsage::GetItem()
{
	return item;
}

int ItemUsage::GetUsageLeft()
{
	return usageLeft;
}

void ItemUsage::UpdateItemUsage()
{
	usageLeft--;

	if (usageLeft <= 0)
		usageLeft = 0;
}

bool ItemUsage::IsUsedUp()
{
	return usageLeft <= 0;
}
