#pragma once
#include "WorldEntity.h"
#include "Screen.h"
#include "Vector2.h"
#include "Interactable.h"
#include <string>
#include <vector>


class Prop : WorldEntity
{
public:
	enum PROPTYPE {
		WALL,
		DOWN_WALL,
		RIGHT_WALL,
		MAP_LAYOUT
	};
private:

	Vector2 boundingBox;

	PROPTYPE propType;

	Interactable* interactable;

	std::string mapLayoutString;
	std::vector<std::string> mapLayoutStringLines;

public:

	Prop(Screen* screenPtr, Vector2 position, Vector2 boundingBox, PROPTYPE propType, Interactable* interactable = nullptr, std::string* mapLayoutString = nullptr);

	~Prop();

	void RenderCharacterDisplay();

	bool IsOverlapping(Vector2 otherPosition);

	Interactable* GetInteractable() const;

	Vector2 GetPosition() const;
};

