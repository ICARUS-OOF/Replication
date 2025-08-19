#pragma once
#include "Vector2.h"

class WorldEntity
{
protected:
	Vector2 position;

public:
	virtual char GetCharacterDisplay() = 0;

	Vector2 GetPosition() const;

};

