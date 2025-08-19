#pragma once

#include "Interactable.h"
#include <string>
#include "Screen.h"

class DialogueInteractable : public Interactable
{
private:
	std::string* dialogueArray;

	Screen* screenPtr;

	int  NumberOfLines;

public:
	DialogueInteractable(std::string* dialogue, Screen* screenPtr, int  NumberOfLines);

	void Interaction();
};

