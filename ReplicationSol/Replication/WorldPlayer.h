#pragma once
#include"Vector2.h"
#include <string>
#include "WorldEntity.h"

class WorldPlayer : public WorldEntity
{

public:
	enum PLAYERDECISION {
		NONE,
		MOVE,
		INTERACT
	};

	Vector2 targetPosition;

	static const int PLAYER_POINTS_SIZE = 6;

	WorldPlayer(Screen* screenPtr, Vector2 startPosition);

	~WorldPlayer();

	void RenderCharacterDisplay();

	void MovePlayer(Vector2 targetPosition);

	PLAYERDECISION GetPlayerInput();

	Vector2* GetPlayerPoints(Vector2 suppliedPosition);

	std::string DEBUG_GETPLAYERPOSITIONSTRING();
};

