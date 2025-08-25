#pragma once

#include "Interactable.h"
#include <string>
#include "Screen.h"
#include "DialogueInteractable.h"
#include "ExitInteractable.h"

class ButtonInteractable : public DialogueInteractable
{
private:
	ExitInteractable* exitInteractable;

public:
	ButtonInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, ExitInteractable* exitInteractable);

	void Interaction();
};

