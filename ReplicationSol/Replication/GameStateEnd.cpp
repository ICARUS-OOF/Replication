#include "GameStateEnd.h"
#include "GAMESTATEVALUE.h"
#include <conio.h>
#include <iostream>

GameStateEnd::GameStateEnd(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();
	this->gameStateScreenSize = Vector2(30, 35);
}


void GameStateEnd::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);
	ClearScreen();
	this->RenderScreen();
}

void GameStateEnd::Loop()
{

}

void GameStateEnd::RenderBaseObjects()
{
}

void GameStateEnd::RenderBaseUI()
{

}

GAMESTATEVALUE GameStateEnd::GetGameStateValue()
{
	return GAMESTATEVALUE::ENDSTATE;
}