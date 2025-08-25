#pragma once

#include "Interactable.h"
#include <string>
#include "Screen.h"

class DialogueInteractable : public Interactable
{
protected:
	std::string* dialogueArray;

	Screen* screenPtr;

	int NumberOfLines;
	int currentInteractionIndex;

	Interactable** gameInteractablePtr;

	

public:
	DialogueInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines);

	virtual void Interaction();
	virtual void Render();
};

