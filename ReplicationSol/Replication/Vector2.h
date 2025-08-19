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

};

