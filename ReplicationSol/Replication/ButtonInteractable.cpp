#include "ButtonInteractable.h"
#include "Interactable.h"
#include <string>
#include "Screen.h"
#include "DialogueInteractable.h"

ButtonInteractable::ButtonInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines) 
	: DialogueInteractable(dialogue, screenPtr, gameInteractablePtr, NumberOfLines)
{
}
