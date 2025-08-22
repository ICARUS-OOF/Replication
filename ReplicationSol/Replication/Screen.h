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
	void ResizeScreen(Vector2 targetSize);
	void ClearScreen();
	char** GetChars();
	void RenderCharacter(const char targetChar, const int targetX, const int targetY);
	void RenderText(Vector2 StartingPos, std::string Text);
	void RenderTextOverflow(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine);
	Vector2 GetScreenSize() const;
	void RenderDrawing(Vector2 StartingPos, const std::string text);
};

