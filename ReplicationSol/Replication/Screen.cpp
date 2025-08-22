#include "Screen.h"

#include "Vector2.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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

void Screen::ResizeScreen(Vector2 targetSize)
{
	for (int i = 0; i < rows; i++)
		delete[] chars[i];
	delete[] chars;

	this->rows = targetSize.Gety();
	this->cols = targetSize.Getx();

	chars = new char* [rows];
	for (int i = 0; i < rows; i++)
		chars[i] = new char[cols];
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

void Screen::RenderCharacter(const char targetChar, const Vector2 pos)
{
	RenderCharacter(targetChar, pos.Getx(), pos.Gety());
}

void Screen::RenderText(Vector2 StartingPos, std::string Text)
{
	for (int i = 0; i < Text.length(); i++)
		RenderCharacter(Text.at(i), StartingPos.Getx() + i, StartingPos.Gety());
}

void Screen::RenderTextWrap(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine)
{
	int currentCharacterCol = 0;
	int currentRow = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		RenderCharacter(Text[i], StartingPos.Getx() + currentCharacterCol, StartingPos.Gety() + currentRow);
		currentCharacterCol++;

		if (currentCharacterCol >= maxCharactersPerLine && Text[i] == ' ') {
			currentRow++;
			currentCharacterCol = 0;
		}
	}
}

void Screen::RenderTextWrapManual(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine)
{
	int currentCharacterCol = 0;
	int currentRow = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != '\n') {
			RenderCharacter(Text[i], StartingPos.Getx() + currentCharacterCol, StartingPos.Gety() + currentRow);
			currentCharacterCol++;
		}

		if (Text[i] == '\n' || (currentCharacterCol >= maxCharactersPerLine && Text[i] == ' ')) {
			currentRow++;
			currentCharacterCol = 0;
		}
	}
}

/// <summary>
/// Gets screen size in the form of a vector2
/// </summary>
/// <returns></returns>
Vector2 Screen::GetScreenSize() const
{
	return Vector2(cols, rows);
}

/// <summary>
/// KAYDEN
/// 
/// Render a drawing onto the screen
/// </summary>
/// <param name="StartingPos"></param>
/// <param name="text"></param>
void Screen::RenderDrawing(Vector2 StartingPos, const std::string text)
{
	std::vector<std::string> lines;
	std::stringstream ss(text);
	std::string line;

	while (std::getline(ss, line, '\n')) {
		lines.push_back(line);
	}

	for (int i = 0; i < lines.size(); i++)
	{
		RenderText(Vector2(StartingPos.Getx(), StartingPos.Gety() + i), lines.at(i));
	}
}
