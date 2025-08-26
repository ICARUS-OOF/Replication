#include "GameStateEnd.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"
#include "MusicHandler.h"
#include <conio.h>
#include <iostream>

GameStateEnd::GameStateEnd(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();
	this->gameStateScreenSize = Vector2(50, 35);
	currentFrame = 0;

	CreateCredits();
	std::reverse(creditLines.begin(), creditLines.end());
}


void GameStateEnd::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);

	MusicHandler::PlayMusic("05_Freedom");

	ClearScreen();
	this->RenderScreen(true);
}

void GameStateEnd::Loop()
{
	currentFrame++;
	if (currentFrame >= creditLines.size())
		currentFrame = creditLines.size() - 1;
	Sleep(400);
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
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, "Thank you for Playing!"));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(13, "_____________________"));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(15, R"(  _        )"));
	creditLines.push_back(CreditName(15, R"( | |       )"));
	creditLines.push_back(CreditName(15, R"( | | _____ )"));
	creditLines.push_back(CreditName(15, R"( | |/ / __|)"));
	creditLines.push_back(CreditName(15, R"( |   < (__ )"));
	creditLines.push_back(CreditName(15, R"( |_|\_\___|)"));
	creditLines.push_back(CreditName(13, ""));
	creditLines.push_back(CreditName(14, "--- Kayden ---"));
	creditLines.push_back(CreditName(14, "-Player Movement"));
	creditLines.push_back(CreditName(14, "-Player Collisions"));
	creditLines.push_back(CreditName(14, "-Player Interactions"));
	creditLines.push_back(CreditName(14, "-Music Class"));
	creditLines.push_back(CreditName(14, "-Dialogue System"));
	creditLines.push_back(CreditName(13, "_____________________"));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(15, R"(     /\         )"));
	creditLines.push_back(CreditName(15, R"(    /  \   __ _ )"));
	creditLines.push_back(CreditName(15, R"(   / /\ \ / _` |)"));
	creditLines.push_back(CreditName(15, R"(  / ____ \ (_| |)"));
	creditLines.push_back(CreditName(15, R"( /_/    \_\__,_|)"));
	creditLines.push_back(CreditName(13, ""));
	creditLines.push_back(CreditName(14, "--- Ahmad ---"));
	creditLines.push_back(CreditName(14, "-Battle UI"));
	creditLines.push_back(CreditName(14, "-Item System"));
	creditLines.push_back(CreditName(14, "-Battle Abilities"));
	creditLines.push_back(CreditName(14, "-Battle Fighting"));
	creditLines.push_back(CreditName(14, "-Battle Navigation"));
	creditLines.push_back(CreditName(13, "_____________________"));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(15, R"( __     ___    _ )"));
	creditLines.push_back(CreditName(15, R"( \ \   / / |  | |)"));
	creditLines.push_back(CreditName(15, R"(  \ \_/ /| |__| |)"));
	creditLines.push_back(CreditName(15, R"(   \   / |  __  |)"));
	creditLines.push_back(CreditName(15, R"(    | |  | |  | |)"));
	creditLines.push_back(CreditName(15, R"(    |_|  |_|  |_|)"));
	creditLines.push_back(CreditName(13, ""));
	creditLines.push_back(CreditName(14, "--- Yu Heng ---"));
	creditLines.push_back(CreditName(14, "-Level Set 1 layout design"));
	creditLines.push_back(CreditName(14, "-GCoin Economy class"));
	creditLines.push_back(CreditName(14, "-Level Battles Layout"));
	creditLines.push_back(CreditName(14, "-Level Wall Layout"));
	creditLines.push_back(CreditName(13, "_____________________"));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(15, R"(   _____    )"));
	creditLines.push_back(CreditName(15, R"(  / ____|   )"));
	creditLines.push_back(CreditName(15, R"( | (___ ____)"));
	creditLines.push_back(CreditName(15, R"(  \___ \_  /)"));
	creditLines.push_back(CreditName(15, R"(  ____) / / )"));
	creditLines.push_back(CreditName(15, R"( |_____/___|)"));
	creditLines.push_back(CreditName(13, ""));
	creditLines.push_back(CreditName(14, "--- Shi Ze ---"));
	creditLines.push_back(CreditName(14, "-Level Set 2 layout design"));
	creditLines.push_back(CreditName(14, "-Level Notes"));
	creditLines.push_back(CreditName(14, "-Collectible Level Items"));
	creditLines.push_back(CreditName(14, "-Puzzle"));
	creditLines.push_back(CreditName(14, "-Vending Machine"));
	creditLines.push_back(CreditName(13, "_____________________"));
	creditLines.push_back(CreditName(14, ""));
	creditLines.push_back(CreditName(15, R"(    _  _____ )"));
	creditLines.push_back(CreditName(15, R"(   (_)/ ____|)"));
	creditLines.push_back(CreditName(15, R"(    _| (___  )"));
	creditLines.push_back(CreditName(15, R"(   | |\___ \ )"));
	creditLines.push_back(CreditName(15, R"(   | |____) |)"));
	creditLines.push_back(CreditName(15, R"(   | |_____/ )"));
	creditLines.push_back(CreditName(15, R"(  _/ |       )"));
	creditLines.push_back(CreditName(15, R"( |__/        )"));
	creditLines.push_back(CreditName(13, ""));
	creditLines.push_back(CreditName(14, "--- Jun Shen ---"));
	creditLines.push_back(CreditName(14, "-Title Screen Animation"));
	creditLines.push_back(CreditName(14, "-Player Animations"));
	creditLines.push_back(CreditName(14, "-Enemy Animations"));
	creditLines.push_back(CreditName(14, "-Sound Effects"));
	creditLines.push_back(CreditName(14, "-Audio Class"));
	creditLines.push_back(CreditName(13, "_____________________"));
	creditLines.push_back(CreditName(13, ""));
	if (gameData->hasLost) {
		creditLines.push_back(CreditName(15, "You have Lost the game"));
	}
	else {
		creditLines.push_back(CreditName(15, "You have escape!"));
	}
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
