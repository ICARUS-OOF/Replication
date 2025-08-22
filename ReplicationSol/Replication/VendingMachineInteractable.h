#pragma once
#include "Interactable.h"
#include <string>
#include "Screen.h"

class VendingMachineInteractable : public Interactable
{
private:
	Screen* screenPtr;

	int currentInteractionIndex;

	Interactable** gameInteractablePtr;



public:
	VendingMachineInteractable(Screen* screenPtr, Interactable** gameInteractablePtr);

	void Interaction();
	void Render();
};

