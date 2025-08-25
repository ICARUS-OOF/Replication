#pragma once

#include "Interactable.h"
#include <string>
#include "Screen.h"
#include "DialogueInteractable.h"

class ButtonInteractable : public DialogueInteractable
{

public:
	ButtonInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines);
};

