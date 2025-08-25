#pragma once

#include "Item.h"
#include "GameData.h"
#include "DialogueInteractable.h"
class PickUpInteractable : public DialogueInteractable
{
private:
	Item item;
	bool hasPickedUp;
	GameData* gameDataPtr;
public:
	PickUpInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, 
		Item item, GameData* gameDataPtr);

	void Interaction();
};