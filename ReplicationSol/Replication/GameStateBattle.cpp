#include "GameStateBattle.h"
#include <conio.h>
#include <iostream>

GameStateBattle::GameStateBattle(Screen* screenPtr)
{
	this->screenPtr = screenPtr;
	this->gameStateScreenSize = Vector2(110, 35);
}

void GameStateBattle::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);
}

void GameStateBattle::GetInputs()
{
	_getch();
}

void GameStateBattle::RenderObjects()
{
}

void GameStateBattle::RenderUI()
{
	Vector2 screenSize = screenPtr->GetScreenSize();

	const int optionBoxLength = 11;

	for (int i = 0; i < screenSize.Getx(); i++)
		screenPtr->RenderCharacter('_', i, 18);
	// Attack
	for (int i = 19; i < 19 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 19);
	screenPtr->RenderCharacter('|', 18, 19+1);
	screenPtr->RenderText(Vector2(20, 20), "1:ATTACK");
	screenPtr->RenderCharacter('|', 30, 19+1);
	for (int i = 19; i < 19 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 21);

	// Item
	for (int i = 19; i < 19 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 22);
	screenPtr->RenderCharacter('|', 18, 22+1);
	screenPtr->RenderText(Vector2(20, 23), "3:ITEM");
	screenPtr->RenderCharacter('|', 30, 22+1);
	for (int i = 19; i < 19 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 24);

	// Ability
	for (int i = 47; i < 47 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 19);
	screenPtr->RenderCharacter('|', 46, 19+1);
	screenPtr->RenderText(Vector2(48, 20), "2:ABILITY");
	screenPtr->RenderCharacter('|', 58, 19+1);
	for (int i = 47; i < 47 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 21);

	// Flee
	for (int i = 47; i < 47 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 22);
	screenPtr->RenderCharacter('|', 46, 22 + 1);
	screenPtr->RenderText(Vector2(48, 23), "4:FLEE");
	screenPtr->RenderCharacter('|', 58, 22 + 1);
	for (int i = 47; i < 47 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 24);

	// Player Health bar
	for (int i = 48; i < 80; i++)
		screenPtr->RenderCharacter('-', i, 14);
	for (int i = 15; i < 18; i++)
		screenPtr->RenderCharacter('|', 48, i);
	screenPtr->RenderText(Vector2(57, 15), "Health: ");
	screenPtr->RenderText(Vector2(57, 16), "Attack: ");
	screenPtr->RenderText(Vector2(57, 17), "Defense: ");


}
