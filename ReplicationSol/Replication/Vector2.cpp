#include "Vector2.h"
#include <cmath>

// INSITIALISE the int x annd y to 0
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

// Constructor which INSITIALISE x and y varibles to x and y
Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

// Get the x variable and returns it
int Vector2::Getx() const
{
	return x;
}

// Get the y variable and returns it
int Vector2::Gety() const
{
	return y;
}

// Set the x variable to x
void Vector2::Setx(int x)
{
    this->x = x;
}

// Set the y variable to y
void Vector2::Sety(int y)
{
    this->y = y;
}

// Set the other x to the x
bool Vector2::IsEqualTo(Vector2 other)
{
	return other.x == x && other.y == y;
}

// Add the original Vector x and y with another supply vector x and y and returns it a new a vector
Vector2 Vector2::AddToVector2(Vector2 add)
{
	return Vector2(x + add.x, y + add.y);
}

// Subtract the original Vector x and y with another supply vector x and y and returns it a new a vector
Vector2 Vector2::SubtractToVector2(Vector2 Subtract)
{
	return Vector2(x - Subtract.x, y - Subtract.y);
}

// Calculate the distance of x and y // OBSOLETE
float Vector2::DistanceToOther(Vector2 Other)
{
	Vector2 difference = SubtractToVector2(Other);

	return sqrtf(difference.x * difference.x + difference.y * difference.y);;
}

// return the vector of x and y into string 
std::string Vector2::Vector2ToString() const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
