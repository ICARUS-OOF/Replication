#include "DialogueInteractable.h"
#include "Screen.h"

#include <conio.h>


DialogueInteractable::DialogueInteractable(std::string* dialogue, Screen* screenPtr, int  NumberOfLines)
{
	this->dialogueArray = dialogue;
	this->screenPtr = screenPtr;
	this->NumberOfLines = NumberOfLines;
}

void DialogueInteractable::Interaction()
{

	static int currentInteractionIndex = 0;
	const int left = 4;
	const int right = 76 - 1;
	const int top = 19;
	const int bottom = 25 - 1;

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

	for (int j = 0; j < dialogueArray[currentInteractionIndex].length(); j++)
			screenPtr->RenderCharacter(dialogueArray[currentInteractionIndex].at(j), dialogueStartLeft + j, dialogueStartTop);
	//DISPLAY DIALOGUE

	currentInteractionIndex++;
	if (currentInteractionIndex >= NumberOfLines)
		currentInteractionIndex = 0;

		
	
}
