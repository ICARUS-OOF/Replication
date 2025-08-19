#include "Screen.h"

/// <summary>
/// KAYDEN
/// 
/// Constructor
/// </summary>
/// <param name="rows"></param>
/// <param name="cols"></param>
Screen::Screen(const int rows, const int cols)
{
	//Sets the max rows and columns
	this->rows = rows;
	this->cols = cols;

	//Create the rows of chars
    chars = new char* [rows];
	//Create the columns of chars
	for (int i = 0; i < rows; i++)
		chars[i] = new char[cols];
}

/// <summary>
/// KAYDEN
/// 
/// Delete all char pointers
/// </summary>
Screen::~Screen()
{
	for (int i = 0; i < rows; i++)
		delete[] chars[i];
	delete[] chars;
}

/// <summary>
/// KAYDEN
/// 
/// Make all chars blank before rendering newframe
/// </summary>
void Screen::ClearScreen()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			chars[i][j] = ' ';
}

/// <summary>
/// Returns the entire 2d array of characters
/// </summary>
/// <returns></returns>
char** Screen::GetChars()
{
    return chars;
}

/// <summary>
/// KAYDEN
/// 
/// If valid position, render a character at that position
/// </summary>
/// <param name="targetChar"></param>
/// <param name="targetX"></param>
/// <param name="targetY"></param>
void Screen::RenderCharacter(const char targetChar, const int targetX, const int targetY)
{
	if (targetX < 0 || targetX >= cols || targetY < 0 || targetY >= rows)
		return;

	chars[targetY][targetX] = targetChar;
}
