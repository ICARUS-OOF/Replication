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
		/*
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
			*/
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
		/*
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
			screenPtr->RenderCharacter('|', left, i);*/
		break;


	default:
		break;
	}
}

/// <summary>
/// According to which type of prop it is, checks whether it is colliding with the provided position
/// </summary>
/// <param name="otherPosition"></param>
/// <param name="isPlayerDirectCollision"></param>
/// <returns></returns>
bool Prop::IsOverlapping(Vector2 otherPosition, bool isPlayerDirectCollision)
{
	bool isOverlappingX = false;
	bool isOverlappingY = false;
	switch (propType)
	{
		//--------BOUNDING BOX OVERLAPPING, MUST BE WITHIN THE X AND Y RANGE--------
	case PROPTYPE::WALL:
	case PROPTYPE::DOWN_WALL:
	case PROPTYPE::RIGHT_WALL:
		isOverlappingX = otherPosition.Getx() >= position.Getx() && otherPosition.Getx() <= (position.Getx() + boundingBox.Getx() - 1);
		isOverlappingY = otherPosition.Gety() >= position.Gety() && otherPosition.Gety() <= (position.Gety() + boundingBox.Gety() - 1);

		return isOverlappingX && isOverlappingY;
		break;

		//----------ALL CHARACTERS OVELRAPPING If map layout, then check every non-empty character if overlapping with exact position-----
	case PROPTYPE::MAP_LAYOUT:
		for (int i = 0; i < mapLayoutStringLines.size(); i++)
			for (int j = 0; j < mapLayoutStringLines[i].size(); j++)
				if (otherPosition.IsEqualTo(Vector2(position.Getx() + j, position.Gety() + i)))
					if (mapLayoutStringLines[i][j] != ' ')
						return true;

		return false;
		break;

		//----------------Similar to Map Layout, but if specified that the player is colliding, then ignore
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

		//------MISC BOUNDING BOX TRIGGERS------
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


//Getter for its interactable
Interactable* Prop::GetInteractable() const
{
	return interactable;
}

//Getter for prop's position
Vector2 Prop::GetPosition() const
{
	return position;
}

//Getter for the room's index
int Prop::GetRoomIndex() const
{
	return roomIndex;
}

//Getter for the type of prop
Prop::PROPTYPE Prop::GetPropType() const
{
	return propType;
}

//If it is a level transition, getter for the room to go to if triggering this level trigger
int Prop::GetRoomTargetLevelTransitionTriggerIndex()
{
	return roomTargetLevelTransitionTriggerIndex;
}

//If it is a level transition, setter for the room to go to if triggering this level trigger
//ONLY USE IF THIS PROP IS A LEVEL TRANSITION
void Prop::SetRoomTargetLevelTransitionTriggerIndex(int targetTransitionRoomIndex)
{
	this->roomTargetLevelTransitionTriggerIndex = targetTransitionRoomIndex;
}

//Getter for the battle index in the gamestateworld's registry
int Prop::GetBattleIndex()
{
	return battleIndex;
}

//If battle trigger, setter for the index of the battle of the gamestateworld
void Prop::SetBattleIndex(int battleIndex)
{
	this->battleIndex = battleIndex;
}

//If room transition, getter for player when emerging from the another room
Vector2 Prop::GetRoomIndexOtherPointPosition()
{
	return *roomIndexOtherPointPosition;
}