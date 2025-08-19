#pragma once
class Vector2
{
private:
	int x, y;

public:
	Vector2();
	Vector2(int x, int y);

	int Getx();
	int Gety();

	void Setx(int x);
	void Sety(int y);

	Vector2 AddToVector2(Vector2 add);
	Vector2 SubtractToVector2(Vector2 Subtract);

	float DistanceToOther(Vector2 Other);


};

