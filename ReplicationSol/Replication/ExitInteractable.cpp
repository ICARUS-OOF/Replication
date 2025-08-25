#include "ExitInteractable.h"
#include "GameData.h"
#include "GAMESTATEVALUE.h"
#include <conio.h>

ExitInteractable::ExitInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, GameData* gameDataPtr)
	: DialogueInteractable(dialogue, screenPtr, gameInteractablePtr, NumberOfLines)
{
	this->isActivated = false;
	this->gameDataPtr = gameDataPtr;
}

void ExitInteractable::Interaction()
{
	if (isActivated) {
		currentInteractionIndex = 0;
		*gameInteractablePtr = nullptr;
		gameDataPtr->SetGameStateValue(GAMESTATEVALUE::ENDSTATE);
	}
	else {
		currentInteractionIndex++;
		if (currentInteractionIndex >= NumberOfLines) {
			currentInteractionIndex = 0;
			*gameInteractablePtr = nullptr;
		}
		_getch();
	}
}

void ExitInteractable::Render()
{
	DialogueInteractable::Render();
}

void ExitInteractable::Activate()
{
	isActivated = true;
}
