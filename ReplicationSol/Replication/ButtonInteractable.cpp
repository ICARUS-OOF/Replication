#include "ButtonInteractable.h"
#include "Interactable.h"
#include <string>
#include "Screen.h"
#include "DialogueInteractable.h"

/// <summary>
/// SHI ZE
/// 
/// The constructor for the button interactable that opens the door to the ending
/// </summary>
/// <param name="dialogue"></param>
/// <param name="screenPtr"></param>
/// <param name="gameInteractablePtr"></param>
/// <param name="NumberOfLines"></param>
/// <param name="exitInteractable"></param>
ButtonInteractable::ButtonInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, ExitInteractable* exitInteractable)
	: DialogueInteractable(dialogue, screenPtr, gameInteractablePtr, NumberOfLines)
{
	this->exitInteractable = exitInteractable;
}


/// <summary>
/// SHI ZE
/// 
/// Activates the exit
/// </summary>
void ButtonInteractable::Interaction()
{
	exitInteractable->Activate();
	DialogueInteractable::Interaction();

}
