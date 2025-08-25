#pragma once

#include "GameState.h"
#include "PlayerStats.h"
#include "GAMESTATEVALUE.h"
#include "GameData.h"
#include "BattleData.h"
#include "Item.h"
#include "ItemUsage.h"
#include <string>
#include <vector>

class GameStateBattle : public GameState
{
public:
	enum BATTLEEVENT {
		PLAYER_CHOICE,
		PLAYER_CHOICE_FIGHT_SELECTENEMY,
		PLAYER_CHOICE_FIGHT_ANIM,
		PLAYER_CHOICE_ITEMS,
		PLAYER_CHOICE_ITEMS_USAGE,
		PLAYER_CHOICE_ABILITIES,
		PLAYER_CHOICE_ABILITIES_USAGE,
		PLAYER_CHOICE_FLEE,
		ENEMY_ATTACK,
		PLAYER_DEATH,
		GAME_WON,
		GAME_RESTART,
	};
private:
	PlayerStats* playerStatsPtr;

	BattleData* currentBattleData;

	/// <summary>
	/// NO CHANGING THIS, USE "SetBattleEvent" INSTEAD!!!!!!!
	/// </summary>
	BATTLEEVENT currentEvent;

	std::string currentConsoleText;

	int currentItemSelected;
	int currentAbilitySelected;

	Item lastItemUsed;

	std::vector <ItemUsage> itemUsages;

	bool abilities_hasUsedRestore;
	int abilities_poisonTurnsLeft;
	int abilities_armourTurnsLeft;

	static const int enemyPoisonWeight = 2;
	static const int enemyHealWeight = 3;
	static const int enemyArmourWeight = 5;

	static const int poisonWeight = 1;
	static const int armourWeight = 5;

	bool isEnemyGuarding = false;
	bool poisonHitPlayer = false;

	int turnNumber;

	int selectedEnemy;

	const float playerFrameInterval = 300;
	const Vector2 playerFramePosition = Vector2(75, 3);
	std::string currentPlayerFrame;
	std::string playerFrame_idle;
	std::vector<std::string> playerFrames_damaged, playerFrames_fight, playerFrames_items, playerFrames_abilities, playerFrames_flee, playerFrames_death, playerFrames_poisoned;

public:
	GameStateBattle(GameData* gameData);

	void OnStateEnter();
	void Loop();
	void RenderBaseObjects();
	void RenderBaseUI();
	GAMESTATEVALUE GetGameStateValue();

	void ApplyItemUsage(Item item);
	void RemoveItemUsage(Item item);
	void UpdateItemUsages();

	void UpdateAbilitiesUsage();

	void SetBattleEvent(BATTLEEVENT targetEvent);

	void ClearConsole();
	void SetConsoleText(std::string targetText);
	std::string GetConsoleText();

	void SetBattleAnimations();
	void PlayAnimationSet(std::vector<std::string> frames, bool resetToIdle);
	void PlayEnemyAnimationSet(EnemyData* targetEnemy, std::vector<std::string> frameSet, bool resetToIdle);
};

