#pragma once
#include "Interactable.h"
#include <string>
#include "Screen.h"

class NoteInteractable : public Interactable
{
private:
	Screen* screenPtr;

	bool isInteracting;

	Interactable** gameInteractablePtr;

	std::string noteText;


public:
	NoteInteractable(Screen* screenPtr, Interactable** gameInteractablePtr, std::string noteText);

	void Interaction();
	void Render();
};

