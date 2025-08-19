#pragma once
#include"Vector2.h"
#include <string>
#include "WorldEntity.h"

class WorldPlayer : public WorldEntity
{

public:

	static const int PLAYER_POINTS_SIZE = 6;

	WorldPlayer(Screen* screenPtr);

	~WorldPlayer();

	void RenderCharacterDisplay();

	void MovePlayer(Vector2 targetPosition);
	Vector2 GetPlayerDesiredPosition();

	Vector2* GetPlayerPoints();

	std::string DEBUG_GETPLAYERPOSITIONSTRING();
};

