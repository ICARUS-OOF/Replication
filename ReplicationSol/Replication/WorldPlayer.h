#pragma once
#include"Vector2.h"
#include <string>
#include "WorldEntity.h"

class WorldPlayer : public WorldEntity
{

public:
	void Move();

	WorldPlayer();
	~WorldPlayer();

	std::string DEBUG_GETPLAYERPOSITIONSTRING();

	char GetCharacterDisplay();
};

