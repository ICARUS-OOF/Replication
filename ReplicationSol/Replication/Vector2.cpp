#include "Vector2.h"
#include <cmath>

void Vector2::Setx(int x)
{
    this->x = x;
}

void Vector2::Sety(int y)
{
    this->y = y;
}

Vector2 Vector2::AddToVector2(Vector2 add)
{
	return Vector2(x + add.x, y + add.y);
}

Vector2 Vector2::SubtractToVector2(Vector2 Subtract)
{
	return Vector2(x - Subtract.x, y - Subtract.y);
}

float Vector2::DistanceToOther(Vector2 Other)
{
	Vector2 difference = SubtractToVector2(Other);

	return sqrtf(difference.x * difference.x + difference.y * difference.y);;
}

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Vector2::Getx()
{
    return x;
}

int Vector2::Gety()
{
    return y;
}
