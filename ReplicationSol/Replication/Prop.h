#pragma once
#include "WorldEntity.h"
#include "Screen.h"
#include "Vector2.h"
#include "Interactable.h"


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

	Interactable* interactable;

public:

	Prop(Screen* screenPtr, Vector2 position, Vector2 boundingBox, PROPTYPE propType, Interactable* interactable = nullptr);

	~Prop();

	void RenderCharacterDisplay();

	bool IsOverlapping(Vector2 otherPosition);

	Interactable* GetInteractable() const;
};

