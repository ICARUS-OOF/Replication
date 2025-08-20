#pragma once

#include "GameState.h"

class GameStateBattle : public GameState
{
public:
	GameStateBattle(Screen* screenPtr);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();
};

