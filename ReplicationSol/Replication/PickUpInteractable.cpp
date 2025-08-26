#include "PickUpInteractable.h"
#include "GameData.h"
#include <conio.h>

/// <summary>
/// KAYDEN
/// 
/// Constructor for pickup interactables for item obtaining
/// </summary>
/// <param name="dialogue"></param>
/// <param name="screenPtr"></param>
/// <param name="gameInteractablePtr"></param>
/// <param name="NumberOfLines"></param>
/// <param name="item"></param>
/// <param name="gameDataPtr"></param>
PickUpInteractable::PickUpInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, Item item, GameData* gameDataPtr)
	: DialogueInteractable(dialogue, screenPtr, gameInteractablePtr, NumberOfLines)
{
	this->item = item;
	this->gameDataPtr = gameDataPtr;
	this->hasPickedUp = false;
}

/// <summary>
/// KAYDEN
/// 
/// Main interaction
/// </summary>
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
