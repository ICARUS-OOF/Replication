#include "DialogueInteractable.h"
#include "Screen.h"
#include "Interactable.h"

#include <conio.h>

/// <summary>
/// KAYDEN
/// 
/// Constructor for dialogue interactable
/// 
/// Takes in a dialogue string array (in the form of a pointer)
/// </summary>
/// <param name="dialogue"></param>
/// <param name="screenPtr"></param>
/// <param name="gameInteractablePtr"></param>
/// <param name="NumberOfLines"></param>
DialogueInteractable::DialogueInteractable(std::string* dialogue, Screen* screenPtr, Interactable** gameInteractablePtr, int NumberOfLines)
{
	this->dialogueArray = dialogue;
	this->screenPtr = screenPtr;
	this->gameInteractablePtr = gameInteractablePtr;
	this->NumberOfLines = NumberOfLines;
	this->currentInteractionIndex = 0;
}

/// <summary>
/// KAYDEN
/// 
/// Interaction with dialogue, increases index every time
/// </summary>
void DialogueInteractable::Interaction()
{
	currentInteractionIndex++;
	//If exceeded, head out of interactable by setting the game interactable to nullptr
	if (currentInteractionIndex >= NumberOfLines) {
		currentInteractionIndex = 0;
		*gameInteractablePtr = nullptr;
	}
	_getch();
}

void DialogueInteractable::Render()
{
	const int left = 4;
	const int right = 76 - 1;
	const int top = 19;
	const int bottom = 25 - 1;
	
	//Dialogue box
	screenPtr->RenderCharacter('+', left, top);

	for (int i = left + 1; i < right; i++)
		screenPtr->RenderCharacter('-', i, top);
	screenPtr->RenderCharacter('+', right, top);


	for (int i = top + 1; i < bottom; i++)
		screenPtr->RenderCharacter('|', right, i);
	screenPtr->RenderCharacter('+', right, bottom);


	for (int i = right - 1; i > left; i--)
		screenPtr->RenderCharacter('-', i, bottom);
	screenPtr->RenderCharacter('+', left, bottom);

	for (int i = bottom - 1; i > top; i--)
		screenPtr->RenderCharacter('|', left, i);

	const int dialogueStartTop = 20;
	const int dialogueStartLeft = 6;
	const int dialogueStartRight = 75;
	const int dialogueStartDown = 25;

	for (int i = dialogueStartTop; i < dialogueStartDown - 1; i++)
		for (int j = dialogueStartLeft - 1; j < dialogueStartRight; j++)
			screenPtr->RenderCharacter(' ', j, i);

	//Dialogue rendering
	for (int j = 0; j < dialogueArray[currentInteractionIndex].length(); j++)
		screenPtr->RenderCharacter(dialogueArray[currentInteractionIndex].at(j), dialogueStartLeft + j, dialogueStartTop);
}
