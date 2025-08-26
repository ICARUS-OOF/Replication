#pragma once

#include "Vector2.h"
#include <string>
#include <windows.h>

class Screen
{
private:
	int rows, cols;
	
	char** chars;

	HANDLE hConsole;

	std::string secondaryText;

public:
	Screen(const int rows, const int cols);
	~Screen();
	void ResizeScreen(Vector2 targetSize);
	void DisplayScreen(Vector2 lastScreenSize, Vector2 lastViewportSize);
	void ClearScreen();
	char** GetChars();

	void RenderCharacter(const char targetChar, const int targetX, const int targetY);
	void RenderCharacter(const char targetChar, const Vector2 pos);
	void RenderText(Vector2 StartingPos, std::string Text);
	void RenderTextWrap(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine);
	void RenderTextWrapManual(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine);
	void RenderSecondaryText(std::string secondaryText);
	Vector2 GetScreenSize() const;
	void RenderDrawing(Vector2 StartingPos, const std::string text);
	Vector2 GetConsoleViewportSize();
};

