#include "Prop.h"
#include "Screen.h"

Prop::Prop(Screen* screenPtr, Vector2 position, Vector2 boundingBox)
{
	this->screenPtr = screenPtr;
	this->position = position;
	this->boundingBox = boundingBox;
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
	screenPtr->RenderCharacter('+', position.Getx() + 0, position.Gety() + 0);
	screenPtr->RenderCharacter('-', position.Getx() + 1, position.Gety() + 0);
	screenPtr->RenderCharacter('+', position.Getx() + 2, position.Gety() + 0);
	screenPtr->RenderCharacter('|', position.Getx() + 2, position.Gety() + 1);
	screenPtr->RenderCharacter('+', position.Getx() + 2, position.Gety() + 2);
	screenPtr->RenderCharacter('-', position.Getx() + 1, position.Gety() + 2);
	screenPtr->RenderCharacter('+', position.Getx() + 0, position.Gety() + 2);
	screenPtr->RenderCharacter('|', position.Getx() + 0, position.Gety() + 1);
}

bool Prop::IsOverlapping(Vector2 otherPosition)
{
	bool isOverlappingX = otherPosition.Getx() >= position.Getx() && otherPosition.Getx() <= (position.Getx() + boundingBox.Getx() - 1);
	bool isOverlappingY = otherPosition.Gety() >= position.Gety() && otherPosition.Gety() <= (position.Gety() + boundingBox.Gety() - 1);

	return isOverlappingX && isOverlappingY;
}
