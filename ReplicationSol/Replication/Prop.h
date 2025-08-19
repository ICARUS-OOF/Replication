#pragma once
#include "WorldEntity.h"
#include "Screen.h"
#include "Vector2.h"

class Prop : WorldEntity
{
private:
	Vector2 boundingBox;

public:
	Prop(Screen* screenPtr, Vector2 position, Vector2 boundingBox);

	~Prop();

	void RenderCharacterDisplay();

	bool IsOverlapping(Vector2 otherPosition);
};

