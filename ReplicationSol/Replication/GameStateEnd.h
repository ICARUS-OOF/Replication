#pragma once
#include "GameState.h"
#include "GameData.h"
#include "GAMESTATEVALUE.h"
#include "Vector2.h"
#include <vector>

class GameStateEnd : public GameState
{
private:
	class CreditName {
	private:
		std::string text;
		int xOffset;
	public:
		CreditName(int xOffset, std::string text);

		std::string GetText();
		int GetYOffset();
	};

	int currentFrame;

	std::vector<CreditName> creditLines;

public:
	GameStateEnd(GameData* gameData);
	void OnStateEnter();
	void Loop();
	void RenderBaseObjects();
	void RenderBaseUI();
	void CreateCredits();
	GAMESTATEVALUE GetGameStateValue();
};

