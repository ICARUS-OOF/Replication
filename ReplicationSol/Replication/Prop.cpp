#include "Prop.h"
#include "Screen.h"
#include <iostream>
#include <sstream>
#include <vector>

Prop::Prop(Screen* screenPtr, int roomIndex, 
	Vector2 position, 
	Vector2 boundingBox, 
	PROPTYPE propType, 
	Interactable* interactable = nullptr, 
	std::string* mapLayoutString = nullptr,
	Vector2* roomIndexOtherPointPosition = nullptr)
{
	this->screenPtr = screenPtr;
	this->roomIndex = roomIndex;
	this->position = position;
	this->boundingBox = boundingBox;
	this->propType = propType;
	this->interactable = interactable;
	if (mapLayoutString != nullptr)
		this->mapLayoutString = *mapLayoutString;
	this->roomIndexOtherPointPosition = roomIndexOtherPointPosition;
	this->battleIndex = battleIndex;

	if (mapLayoutString != nullptr) {
		std::stringstream ss(*mapLayoutString);
		std::string line;

		while (std::getline(ss, line, '\n')) {
			mapLayoutStringLines.push_back(line);
		}
	}
}

Prop::~Prop()
{

}


/// <summary>
/// Ahmad
/// 
/// Render the Wall Prop
/// </summary>
void Prop::RenderCharacterDisplay()
{
	const int left = position.Getx();
	const int right = position.Getx() + boundingBox.Getx() - 1;
	const int top = position.Gety();
	const int bottom = position.Gety() + boundingBox.Gety() - 1;
	switch (propType)
	{
	case PROPTYPE::WALL:

		screenPtr->RenderCharacter('+', left, top);

		for (int i = left + 1; i < right; i++)
			screenPtr->RenderCharacter('-', i, top);
		screenPtr->RenderCharacter('+', right, top);


		for (int i = top + 1; i < bottom; i++)
			screenPtr->RenderCharacter('|', right, i);
		screenPtr->RenderCharacter('+', right, bottom);


		for (int i = right - 1; i > left; i--)
			screenPtr->RenderCharacter('-', i, bottom);
		screenPtr->RenderCharacter('+', left, bottom);

		for (int i = bottom - 1; i > top; i--)
			screenPtr->RenderCharacter('|', left, i);

		break;

	case PROPTYPE::RIGHT_WALL:
		if (top != bottom) {
			std::cout << "HORIZONTAL WALL HEIGHT NOT 1" << std::endl;
			break;
		}

		screenPtr->RenderCharacter('+', left, top);
		for (int i = left + 1; i < right; i++)
			screenPtr->RenderCharacter('-', i, top);
		screenPtr->RenderCharacter('+', right, top);

		break;

	case PROPTYPE::DOWN_WALL:
		if (left != right) {
			std::cout << "VERTICAL WALL WIDTH NOT 1" << std::endl;
			break;
		}

		screenPtr->RenderCharacter('+', left, top);
		for (int i = top + 1; i < bottom; i++)
			screenPtr->RenderCharacter('|', left, i);
		screenPtr->RenderCharacter('+', left, bottom);

		break;

	case PROPTYPE::MAP_LAYOUT:
	case PROPTYPE::MAP_LAYOUT_NONSOLID:
		screenPtr->RenderDrawing(position, mapLayoutString);
		break;

	case PROPTYPE::BATTLE_TRIGGER:
	case PROPTYPE::LEVEL_TRANSITION_TRIGGER:
		screenPtr->RenderCharacter('+', left, top);

		for (int i = left + 1; i < right; i++)
			screenPtr->RenderCharacter('-', i, top);
		screenPtr->RenderCharacter('+', right, top);


		for (int i = top + 1; i < bottom; i++)
			screenPtr->RenderCharacter('|', right, i);
		screenPtr->RenderCharacter('+', right, bottom);


		for (int i = right - 1; i > left; i--)
			screenPtr->RenderCharacter('-', i, bottom);
		screenPtr->RenderCharacter('+', left, bottom);

		for (int i = bottom - 1; i > top; i--)
			screenPtr->RenderCharacter('|', left, i);
		break;


	default:
		break;
	}
}

bool Prop::IsOverlapping(Vector2 otherPosition, bool isPlayerDirectCollision)
{
	bool isOverlappingX = false;
	bool isOverlappingY = false;
	switch (propType)
	{
	case PROPTYPE::WALL:
	case PROPTYPE::DOWN_WALL:
	case PROPTYPE::RIGHT_WALL:
		isOverlappingX = otherPosition.Getx() >= position.Getx() && otherPosition.Getx() <= (position.Getx() + boundingBox.Getx() - 1);
		isOverlappingY = otherPosition.Gety() >= position.Gety() && otherPosition.Gety() <= (position.Gety() + boundingBox.Gety() - 1);

		return isOverlappingX && isOverlappingY;
		break;

	case PROPTYPE::MAP_LAYOUT:
		for (int i = 0; i < mapLayoutStringLines.size(); i++)
			for (int j = 0; j < mapLayoutStringLines[i].size(); j++)
				if (otherPosition.IsEqualTo(Vector2(position.Getx() + j, position.Gety() + i)))
					if (mapLayoutStringLines[i][j] != ' ')
						return true;

		return false;
		break;


	case PROPTYPE::MAP_LAYOUT_NONSOLID:
		if (!isPlayerDirectCollision) {
			for (int i = 0; i < mapLayoutStringLines.size(); i++)
				for (int j = 0; j < mapLayoutStringLines[i].size(); j++)
					if (otherPosition.IsEqualTo(Vector2(position.Getx() + j, position.Gety() + i)))
						if (mapLayoutStringLines[i][j] != ' ')
							return true;

			return false;
		}
		else {
			return false;
		}
		break;

	case PROPTYPE::BATTLE_TRIGGER:
	case PROPTYPE::LEVEL_TRANSITION_TRIGGER:
		isOverlappingX = otherPosition.Getx() >= position.Getx() && otherPosition.Getx() <= (position.Getx() + boundingBox.Getx() - 1);
		isOverlappingY = otherPosition.Gety() >= position.Gety() && otherPosition.Gety() <= (position.Gety() + boundingBox.Gety() - 1);

		return isOverlappingX && isOverlappingY;
		break;

	default:
		return true;
	}

	return false;
}


Interactable* Prop::GetInteractable() const
{
	return interactable;
}

Vector2 Prop::GetPosition() const
{
	return position;
}

int Prop::GetRoomIndex() const
{
	return roomIndex;
}

Prop::PROPTYPE Prop::GetPropType() const
{
	return propType;
}

int Prop::GetRoomTargetLevelTransitionTriggerIndex()
{
	return roomTargetLevelTransitionTriggerIndex;
}

void Prop::SetRoomTargetLevelTransitionTriggerIndex(int targetTransitionRoomIndex)
{
	this->roomTargetLevelTransitionTriggerIndex = targetTransitionRoomIndex;
}

void Prop::SetBattleIndex(int battleIndex)
{
	this->battleIndex = battleIndex;
}

int Prop::GetBattleIndex()
{
	return battleIndex;
}

Vector2 Prop::GetRoomIndexOtherPointPosition()
{
	return *roomIndexOtherPointPosition;
}