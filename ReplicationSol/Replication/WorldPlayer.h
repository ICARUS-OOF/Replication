#pragma once
#include"Vector2.h"
#include <string>
#include "WorldEntity.h"

class WorldPlayer : public WorldEntity
{
private:
	Vector2* solidPoints;
	Vector2* interactivePoints;

public:
	enum PLAYERDECISION {
		NONE,
		MOVE,
		INTERACT,
		RUN_TESTBATTLE
	};

	Vector2 targetPosition;

	static const int PLAYER_POINTS_SIZE = 6;
	static const int INTERACTIVE_POINTS_SIZE = 15;

	float interactionRange = 2.0f;

	WorldPlayer(Screen* screenPtr, Vector2 startPosition);

	~WorldPlayer();

	void RenderCharacterDisplay();

	void MovePlayer(Vector2 targetPosition);

	PLAYERDECISION GetPlayerInput();

	Vector2* GetPlayerPoints(Vector2 suppliedPosition);
	Vector2* GetInteractivePoints(Vector2 suppliedPosition);



	std::string DEBUG_GETPLAYERPOSITIONSTRING();
};

