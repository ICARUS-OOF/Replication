#pragma once
#include"Vector2.h"

class Player
{
private:
	Vector2 position;

public:
	void move();

	Player();
	~Player();
};

