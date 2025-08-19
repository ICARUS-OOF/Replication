#pragma once
#include "WorldEntity.h"
#include "Screen.h"
#include "Vector2.h"


class Prop : WorldEntity
{
public:
	enum PROPTYPE {
		WALL,
		DOWN_WALL,
		RIGHT_WALL
	};
private:

	Vector2 boundingBox;

	PROPTYPE propType;

public:

	Prop(Screen* screenPtr, Vector2 position, Vector2 boundingBox, PROPTYPE propType);

	~Prop();

	void RenderCharacterDisplay();

	bool IsOverlapping(Vector2 otherPosition);
};

