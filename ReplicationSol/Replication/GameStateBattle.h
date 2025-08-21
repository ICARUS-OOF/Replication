#pragma once

#include "GameState.h"
#include "PlayerStats.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"
#include "BattleData.h"
#include <string>

class GameStateBattle : public GameState
{
public:
	enum BATTLEEVENT {
		PLAYER_CHOICE,
		PLAYER_CHOICE_FIGHT_SELECTENEMY,
		PLAYER_CHOICE_FIGHT_ANIM,
		PLAYER_CHOICE_ITEMS,
		PLAYER_CHOICE_ABILITIES,
		PLAYER_CHOICE_FLEE,
		ENEMY_ATTACK,
		GAME_RESTART
	};
private:
	PlayerStats* playerStatsPtr;

	GameData* gameData;

	BattleData* currentBattleData;

	BATTLEEVENT currentEvent;

	std::string currentConsoleText;
public:
	GameStateBattle(GameData* gameData);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();
	GAMESTATEVALUE GetGameStateValue();

	void SetConsoleText(std::string targetText);
	std::string GetConsoleText();
};

