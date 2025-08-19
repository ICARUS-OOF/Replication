#pragma once

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
	void RenderCharacter(const char targetChar, const int targetRow, const int targetCol);
};

