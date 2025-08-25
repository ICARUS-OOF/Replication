#include "PickUpInteractable.h"
#include "GameData.h"
#include <conio.h>

PickUpInteractable::PickUpInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, Item item, GameData* gameDataPtr)
	: DialogueInteractable(dialogue, screenPtr, gameInteractablePtr, NumberOfLines)
{
	this->item = item;
	this->gameDataPtr = gameDataPtr;
	this->hasPickedUp = false;
}

void PickUpInteractable::Interaction()
{
	currentInteractionIndex++;
	if (currentInteractionIndex >= NumberOfLines) {
		gameDataPtr->AddItem(item);
		canInteract = false;
		currentInteractionIndex = 0;
		*gameInteractablePtr = nullptr;
	}
	_getch();

}
