#include "Prop.h"
#include "Screen.h"

Prop::Prop(Screen* screenPtr, Vector2 position)
{
	this->screenPtr = screenPtr;
	this->position = position;
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
	screenPtr->RenderCharacter('+', position.Getx() - 1, position.Gety() - 1);
	screenPtr->RenderCharacter('-', position.Getx() + 0, position.Gety() - 1);
	screenPtr->RenderCharacter('+', position.Getx() + 1, position.Gety() - 1);
	screenPtr->RenderCharacter('|', position.Getx() + 1, position.Gety() + 0);
	screenPtr->RenderCharacter('+', position.Getx() + 1, position.Gety() + 1);
	screenPtr->RenderCharacter('-', position.Getx() + 0, position.Gety() + 1);
	screenPtr->RenderCharacter('+', position.Getx() - 1, position.Gety() + 1);
	screenPtr->RenderCharacter('|', position.Getx() - 1, position.Gety() + 0);
}
