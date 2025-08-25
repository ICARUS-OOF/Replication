#pragma once

#include "Interactable.h"
#include <string>
#include "Screen.h"
#include "GameData.h"
#include "DialogueInteractable.h"

class ExitInteractable : public DialogueInteractable
{
private:
	GameData* gameDataPtr;
	bool isActivated;

public:

	ExitInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, GameData* gameDataPtr);
	void Interaction();
	void Render();

	void Activate();
};

