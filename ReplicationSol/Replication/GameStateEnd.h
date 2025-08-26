#pragma once
#include "GameState.h"
#include "GameData.h"
#include "GAMESTATEVALUE.h"
#include "Vector2.h"

class GameStateEnd : public GameState
{
private:
	int currentFrame;

public:
	GameStateEnd(GameData* gameData);
	void OnStateEnter();
	void Loop();
	void RenderBaseObjects();
	void RenderBaseUI();
	GAMESTATEVALUE GetGameStateValue();
};

