#include "GameStateEnd.h"
#include "GAMESTATEVALUE.h"
#include <conio.h>
#include <iostream>

GameStateEnd::GameStateEnd(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();
	this->gameStateScreenSize = Vector2(30, 35);
	currentFrame = 0;
}


void GameStateEnd::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);
	ClearScreen();
	this->RenderScreen(true);
}

void GameStateEnd::Loop()
{
	currentFrame++;
	Sleep(2000);
	this->RenderScreen(true);
}

void GameStateEnd::RenderBaseObjects()
{
}

void GameStateEnd::RenderBaseUI()
{
	if (currentFrame == 0) {
		screenPtr->RenderText(Vector2(0, 0), "Kayden Chai");
	}
	else if (currentFrame == 1) {
		screenPtr->RenderText(Vector2(0, 0), "Ahmad ");
		screenPtr->RenderText(Vector2(0, 1), "Kayden Chai");
	}
}

GAMESTATEVALUE GameStateEnd::GetGameStateValue()
{
	return GAMESTATEVALUE::ENDSTATE;
}