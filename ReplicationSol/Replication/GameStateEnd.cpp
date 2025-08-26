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

	CreateCredits();
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
	if (currentFrame >= creditLines.size())
		currentFrame = creditLines.size() - 1;
	Sleep(2000);
	this->RenderScreen(true);
}

void GameStateEnd::RenderBaseObjects()
{

}

void GameStateEnd::RenderBaseUI()
{
	for (int i = currentFrame; i >= 0; i--)
	{
		screenPtr->RenderText(Vector2(creditLines[i].GetYOffset(), currentFrame - i), creditLines[i].GetText());
	}
}



void GameStateEnd::CreateCredits()
{
	creditLines.push_back(CreditName(10, "Kayden Chai"));
}




GAMESTATEVALUE GameStateEnd::GetGameStateValue()
{
	return GAMESTATEVALUE::ENDSTATE;
}







GameStateEnd::CreditName::CreditName(int xOffset, std::string text)
{
	this->text = text;
	this->xOffset = xOffset;
}

std::string GameStateEnd::CreditName::GetText()
{
	return text;
}

int GameStateEnd::CreditName::GetYOffset()
{
	return xOffset;
}
