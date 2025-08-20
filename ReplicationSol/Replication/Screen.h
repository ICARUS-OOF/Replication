#pragma once

#include "Vector2.h"
#include <string>

class Screen
{
private:
	int rows, cols;
	
	char** chars;

public:
	Screen(const int rows, const int cols);
	~Screen();
	void ClearScreen();
	char** GetChars();
	void RenderCharacter(const char targetChar, const int targetX, const int targetY);
	void RenderText(Vector2 StartingPos, std::string Text);
	Vector2 GetScreenSize() const;
};

