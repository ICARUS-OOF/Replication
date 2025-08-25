#pragma once
#include "Interactable.h"
#include <string>
#include "Screen.h"
#include "GameData.h"

class VendingMachineInteractable : public Interactable
{
private:
	Screen* screenPtr;

	int currentInteractionIndex;

	Interactable** gameInteractablePtr;

	bool isBuying;
	int vmIndex;

	bool hasBoughtItem[3] = { false, false, false };

	GameData* gameDataptr;

public:
	VendingMachineInteractable(Screen* screenPtr, Interactable** gameInteractablePtr, int vmIndex, GameData* gameDataptr);

	void Interaction();
	void Render();
};

