#pragma once

#include "Screen.h"
#include "GAMESTATEVALUE.h"

class GameState
{
protected:
	Screen* screenPtr;
	Vector2 gameStateScreenSize;

public:
	virtual void OnStateEnter() = 0;
	virtual void GetInputs() = 0;
	virtual void RenderObjects() = 0;
	virtual void RenderUI() = 0;
	virtual GAMESTATEVALUE GetGameStateValue() = 0;
};

