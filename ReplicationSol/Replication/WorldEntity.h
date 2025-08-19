#pragma once
#include "Vector2.h"
#include "Screen.h"

class WorldEntity
{
protected:
	Vector2 position;
	Screen* screenPtr;

public:
	virtual void RenderCharacterDisplay() = 0;

	Vector2 GetPosition() const;

};

