#include "ItemUsage.h"
#include "Item.h"

/// <summary>
/// AHMAD
/// 
/// Constructor which INSITIALISE variables of the item usage
/// </summary>
/// <param name="item"></param>
/// <param name="usageLeft"></param>
ItemUsage::ItemUsage(Item item, int usageLeft)
{
	this->item = item;
	this->usageLeft = usageLeft + 1;
}

// Get the set item and returns it
Item ItemUsage::GetItem()
{
	return item;
}

// Get the item Usage Left from any item and return it
int ItemUsage::GetUsageLeft()
{
	return usageLeft;
}

// Updating the item usage by -1 and when it reaches 0 set it to 0
void ItemUsage::UpdateItemUsage()
{
	usageLeft--;

	if (usageLeft <= 0)
		usageLeft = 0;
}

// When the item is used up set the usage left amount to 0
bool ItemUsage::IsUsedUp()
{
	return usageLeft <= 0;
}
