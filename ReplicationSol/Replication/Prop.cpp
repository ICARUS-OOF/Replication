#include "Prop.h"
#include "Screen.h"
#include <iostream>

Prop::Prop(Screen* screenPtr, Vector2 position, Vector2 boundingBox, PROPTYPE propType, Interactable* interactable)
{
	this->screenPtr = screenPtr;
	this->position = position;
	this->boundingBox = boundingBox;
	this->propType = propType;
	this->interactable = interactable;
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



	default:
		break;
	}
}

bool Prop::IsOverlapping(Vector2 otherPosition)
{
	bool isOverlappingX = otherPosition.Getx() >= position.Getx() && otherPosition.Getx() <= (position.Getx() + boundingBox.Getx() - 1);
	bool isOverlappingY = otherPosition.Gety() >= position.Gety() && otherPosition.Gety() <= (position.Gety() + boundingBox.Gety() - 1);

	return isOverlappingX && isOverlappingY;
}

Interactable* Prop::GetInteractable() const
{
	return interactable;
}
