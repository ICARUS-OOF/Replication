#include "ExitInteractable.h"
#include "GameData.h"
#include "GAMESTATEVALUE.h"
#include <conio.h>

/// <summary>
/// SHI ZE
/// 
/// CONSTRUCTOR
/// 
/// Exit Interactable to trigger the ending of the game
/// Calls base constructor as it extends DialogueInteractable
/// </summary>
/// <param name="dialogue"></param>
/// <param name="screenPtr"></param>
/// <param name="gameInteractablePtr"></param>
/// <param name="NumberOfLines"></param>
/// <param name="gameDataPtr"></param>
ExitInteractable::ExitInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines, GameData* gameDataPtr)
	: DialogueInteractable(dialogue, screenPtr, gameInteractablePtr, NumberOfLines)
{
	this->isActivated = false;
	this->gameDataPtr = gameDataPtr;
}

/// <summary>
/// SHI ZE
/// 
/// Interaction with the exit
/// </summary>
void ExitInteractable::Interaction()
{
	//If activated, jump to game end state
	if (isActivated) {
		currentInteractionIndex = 0;
		*gameInteractablePtr = nullptr;
		gameDataPtr->SetGameStateValue(GAMESTATEVALUE::ENDSTATE);
	}
	else {
		//If not activated yet, display dialogue
		currentInteractionIndex++;
		if (currentInteractionIndex >= NumberOfLines) {
			currentInteractionIndex = 0;
			*gameInteractablePtr = nullptr;
		}
		_getch();
	}
}

/// <summary>
/// Render just calls base's render
/// </summary>
void ExitInteractable::Render()
{
	DialogueInteractable::Render();
}

/// <summary>
/// Activate the exit so that player can exit game
/// </summary>
void ExitInteractable::Activate()
{
	isActivated = true;
}
