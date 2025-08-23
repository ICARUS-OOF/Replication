#pragma once

#include "Screen.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"

class GameState
{
protected:
	Screen* screenPtr;
	Vector2 gameStateScreenSize;
	GameData* gameData;

	void RenderScreen(bool clearScreen = true);

	void ClearScreen();

	virtual void RenderBaseObjects() = 0;
	virtual void RenderBaseUI() = 0;

public:
	virtual void OnStateEnter() = 0;
	virtual void Loop() = 0;
	virtual GAMESTATEVALUE GetGameStateValue() = 0;
};

