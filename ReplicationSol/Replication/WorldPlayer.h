#pragma once
#include"Vector2.h"
#include <string>

class WorldPlayer
{
private:
	Vector2 position;

public:
	void Move();

	WorldPlayer();
	~WorldPlayer();

	std::string DEBUG_GETPLAYERPOSITIONSTRING();
};

