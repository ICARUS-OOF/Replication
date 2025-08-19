#pragma once
#include "WorldEntity.h"
#include "Screen.h"
#include "Vector2.h"

class Prop : WorldEntity
{
public:
	Prop(Screen* screenPtr, Vector2 position);

	~Prop();

	void RenderCharacterDisplay();
};

