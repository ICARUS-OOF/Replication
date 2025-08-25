#include "VendingMachineInteractable.h"
#include "Screen.h"
#include "Interactable.h"

#include <conio.h>

VendingMachineInteractable::VendingMachineInteractable(Screen* screenPtr, Interactable** gameInteractablePtr)
{
	this->screenPtr = screenPtr;
	this->gameInteractablePtr = gameInteractablePtr;
	this->currentInteractionIndex = 0;
}

void VendingMachineInteractable::Interaction()
{
	currentInteractionIndex++;
	if (currentInteractionIndex >= 3) {
		currentInteractionIndex = 0;
		*gameInteractablePtr = nullptr;
	}
	_getch();
}

void VendingMachineInteractable::Render()
{
	const int top = 1;
	const int left = 1;
	const int right = 79 - 1;
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

	const int dialogueStartTop = 2;
	const int dialogueStartLeft = 3;
	const int dialogueStartRight = 78;
	const int dialogueStartDown = 25;

	for (int i = dialogueStartTop; i < dialogueStartDown - 1; i++)
		for (int j = dialogueStartLeft - 1; j < dialogueStartRight; j++)
			screenPtr->RenderCharacter(' ', j, i);


	{
		////----RENDER CHARACTER---
		//screenPtr->RenderCharacter('X', Vector2(5, 10));

		////---SERIES OF CHARACTERS---
		//for (int i = 5; i < 11; i++)
		//{
		//	screenPtr->RenderCharacter('X', Vector2(i, 10));
		//}

		////----RENDERING DRAWING---
		//std::string myDrawing = R"(    ______________
  //|              |
  //|   [====]     |
  //|   [====]     |
  //|   [====]     |
  //|   [====]     |
  //|______________|)";
		//screenPtr->RenderDrawing(Vector2(40, 6), myDrawing);

		////------RENDER TEXT------
		//screenPtr->RenderText(Vector2(3, 3), "You found a vending machine!");
		//screenPtr->RenderTextWrap(Vector2(3, 6), "You found a vending machine!", 10);
	}




}
