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
		GAME_WON,
		GAME_RESTART,
	};
private:
	PlayerStats* playerStatsPtr;

	GameData* gameData;

	BattleData* currentBattleData;

	/// <summary>
	/// NO CHANGING THIS, USE "SetBattleEvent" INSTEAD!!!!!!!
	/// </summary>
	BATTLEEVENT currentEvent;

	std::string currentConsoleText;

	int currentFrame;
	int currentItemSelected;
public:
	GameStateBattle(GameData* gameData);

	void OnStateEnter();
	void GetInputs();
	void RenderObjects();
	void RenderUI();
	GAMESTATEVALUE GetGameStateValue();

	void SetBattleEvent(BATTLEEVENT targetEvent);

	void ClearConsole();
	void SetConsoleText(std::string targetText);
	std::string GetConsoleText();
};

