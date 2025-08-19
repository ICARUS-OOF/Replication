#include "Vector2.h"


void Vector2::Setx(int x)
{
    this->x = x;
}

void Vector2::Sety(int y)
{
    this->y = y;
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
