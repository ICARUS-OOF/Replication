#pragma once
#include "GameState.h"
#include "GameData.h"
#include "GAMESTATEVALUE.h"

class GameStateEnd : public GameState
{

public:
	GameStateEnd(GameData* gameData);
	void OnStateEnter();
	void Loop();
	void RenderBaseObjects();
	void RenderBaseUI();
	GAMESTATEVALUE GetGameStateValue();
};

