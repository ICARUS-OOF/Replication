#pragma once

#include "GameState.h"
#include "PlayerStats.h"

class GameStateBattle : public GameState
{
private:
	PlayerStats* playerStatsPtr;
public:
	GameStateBattle(Screen* screenPtr, PlayerStats* playerStatsPtr);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();
};

