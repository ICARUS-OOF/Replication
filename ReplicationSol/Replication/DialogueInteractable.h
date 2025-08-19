#pragma once

#include "Interactable.h"
#include <string>
#include "Screen.h"

class DialogueInteractable : public Interactable
{
private:
	std::string dialogue;

	Screen* screenPtr;

public:
	DialogueInteractable(std::string dialogue, Screen* screenPtr);

	void Interaction();
};

