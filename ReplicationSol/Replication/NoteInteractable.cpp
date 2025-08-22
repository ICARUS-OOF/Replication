#include "NoteInteractable.h"
#include "Screen.h"
#include "Interactable.h"

#include <conio.h>

NoteInteractable::NoteInteractable(Screen* screenPtr, Interactable** gameInteractablePtr, std::string noteText)
{
	this->screenPtr = screenPtr;
	this->gameInteractablePtr = gameInteractablePtr;
	this->isInteracting = false;
	this->noteText = "<------------   NOTE DISCOVERED  ------------>\n\n" +  noteText;
}

void NoteInteractable::Interaction()
{
	isInteracting != isInteracting;
	if (!isInteracting) {
		*gameInteractablePtr = nullptr;
	}
	_getch();
}

void NoteInteractable::Render()
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

	screenPtr->RenderTextWrapManual(Vector2(4, 2), noteText, 60);
}
