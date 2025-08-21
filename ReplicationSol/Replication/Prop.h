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
		MAP_LAYOUT,
		MAP_LAYOUT_NONSOLID,
		LEVEL_TRANSITION_TRIGGER,
	};
private:

	Vector2 boundingBox;

	PROPTYPE propType;

	Interactable* interactable;

	std::string mapLayoutString;
	std::vector<std::string> mapLayoutStringLines;

	int roomIndex;

	Vector2* roomIndexOtherPointPosition;

	int roomTargetLevelTransitionTriggerIndex = 0;

public:

	Prop(Screen* screenPtr, int roomIndex, Vector2 position, Vector2 boundingBox, PROPTYPE propType, Interactable* interactable, std::string* mapLayoutString, Vector2* roomIndexOtherPointPosition);

	~Prop();

	void RenderCharacterDisplay();

	bool IsOverlapping(Vector2 otherPosition, bool isPlayerDirectCollision);

	Interactable* GetInteractable() const;

	Vector2 GetPosition() const;

	int GetRoomIndex() const;

	PROPTYPE GetPropType() const;

	int GetRoomTargetLevelTransitionTriggerIndex();
	void SetRoomTargetLevelTransitionTriggerIndex(int targetTransitionRoomIndex);

	Vector2 GetRoomIndexOtherPointPosition();
};

