#include "Screen.h"

#include "Vector2.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <windows.h>

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

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	this->secondaryText = "";
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

	system("cls");
}

/// <summary>
/// KAYDEN
/// 
/// Main function to display the entire screen
/// </summary>
/// <param name="lastScreenSize"></param>
/// <param name="lastViewportSize"></param>
void Screen::DisplayScreen(Vector2 lastScreenSize, Vector2 lastViewportSize)
{
	Vector2 screenSize = GetScreenSize();
	int cols = screenSize.Getx();
	int rows = screenSize.Gety();

	//If screen size was resized, then clear screen
	if (!lastScreenSize.IsEqualTo(screenSize))
		system("cls");

	//If viewport size was last changed, then clear screen
	Vector2 currentViewportSize = GetConsoleViewportSize();
	if (!lastViewportSize.IsEqualTo(currentViewportSize))
		system("cls");

	{
		//String stream to collate all character data into a single string to print efficiently
		std::stringstream ss;
		//Top Border
		ss << '+';
		for (int i = 0; i < cols; i++)
			ss << '-';
		ss << '+';

		//World Content
		for (int i = 0; i < rows; i++)
		{
			//Leave a new line
			ss << std::endl;

			//Left Border
			ss << '|';

			//Display each character
			for (int j = 0; j < cols; j++) {
				if ((int)chars[i][j] != 9) {
					ss << chars[i][j];
				}
				else {
					ss << ' ';
				}
			}

			//Right Border
			ss << '|';
		}

		//Leave new line
		ss << std::endl;

		//Bottom border
		ss << '+';
		for (int i = 0; i < cols; i++)
			ss << '-';
		ss << '+';

		//Secondary text rendering
		ss << std::endl;
		std::string _secondaryTextFinal;
		for (int i = 0; i < 80; i++)
		{
			if (i < secondaryText.size())
				_secondaryTextFinal += secondaryText[i];
			else
				_secondaryTextFinal += ' ';
		}
		ss << _secondaryTextFinal;
		ss << std::endl;

		//Resetting cursor to 0,0 for printing over
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOut, { 0, 0 });
		std::cout << ss.str();
	}
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
/// KAYDEN
/// 
/// Gets the actual console's window viewport size, not the game's
/// </summary>
/// <returns></returns>
Vector2 Screen::GetConsoleViewportSize()
{
	//Get standard ouput handler
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Contains info about the console screen
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

	//If successful in obtaining the csbi
	if (GetConsoleScreenBufferInfo(hOut, &bufferInfo))
	{
		//Obtain the width and height of window
		int windowWidth = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1; //Difference from left ro right - 1 unit
		int windowHeight = bufferInfo.srWindow.Bottom - bufferInfo.srWindow.Top + 1; //Difference from top to bottom - 1 unit

		//Return a vector containing these 2
		return Vector2(windowWidth, windowHeight);
	}

	//If could not obtain buffer Info, return 0,0 failure
	return Vector2(0, 0);
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
	//If not within the screen size, do not render
	if (targetX < 0 || targetX >= cols || targetY < 0 || targetY >= rows)
		return;

	chars[targetY][targetX] = targetChar;
}

/// <summary>
/// KAYDEN
/// 
/// Overload for RenderCharacter, taking a Vector2 pos for character rendering instead
/// </summary>
/// <param name="targetChar"></param>
/// <param name="pos"></param>
void Screen::RenderCharacter(const char targetChar, const Vector2 pos)
{
	RenderCharacter(targetChar, pos.Getx(), pos.Gety());
}

/// <summary>
/// KAYDEN
/// 
/// At "StartingPos", start rendering text towards the right
/// </summary>
/// <param name="StartingPos"></param>
/// <param name="Text"></param>
void Screen::RenderText(Vector2 StartingPos, std::string Text)
{
	//For every text character, move to the right by 1 to render the characters
	for (int i = 0; i < Text.length(); i++)
		RenderCharacter(Text.at(i), StartingPos.Getx() + i, StartingPos.Gety());
}

/// <summary>
/// KAYDEN
/// 
/// Render text but capping at a max num characters per line with a space
/// </summary>
/// <param name="StartingPos"></param>
/// <param name="Text"></param>
/// <param name="maxCharactersPerLine"></param>
void Screen::RenderTextWrap(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine)
{
	int currentCharacterCol = 0;
	int currentRow = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		//Render characters with the offset of currentCharacterCol
		RenderCharacter(Text[i], StartingPos.Getx() + currentCharacterCol, StartingPos.Gety() + currentRow);
		currentCharacterCol++;

		//If the column exceeds maxCharactersPerLine and if the current character is a space, move down by 1 row and reset to the left
		if (currentCharacterCol >= maxCharactersPerLine && Text[i] == ' ') {
			currentRow++;
			currentCharacterCol = 0;
		}
	}
}

/// <summary>
/// KAYDEN
/// 
/// Similar to RenderTextWrap
/// However, text can include the character '\n' to signify a new line manually
/// </summary>
/// <param name="StartingPos"></param>
/// <param name="Text"></param>
/// <param name="maxCharactersPerLine"></param>
void Screen::RenderTextWrapManual(Vector2 StartingPos, std::string Text, const int maxCharactersPerLine)
{
	int currentCharacterCol = 0;
	int currentRow = 0;

	for (int i = 0; i < Text.length(); i++)
	{
		//If character isn't a new line yet, render the character
		if (Text[i] != '\n') {
			RenderCharacter(Text[i], StartingPos.Getx() + currentCharacterCol, StartingPos.Gety() + currentRow);
			currentCharacterCol++;
		}

		//(If the character is detected to be a new line '\n') OR (if column exceeds maxCharactersPerLine and if current character is a space)
		if (Text[i] == '\n' || (currentCharacterCol >= maxCharactersPerLine && Text[i] == ' ')) {
			currentRow++;
			currentCharacterCol = 0;
		}
	}
}

/// <summary>
/// KAYDEN
/// 
/// Set Secondary text
/// </summary>
/// <param name="secondaryText"></param>
void Screen::RenderSecondaryText(std::string secondaryText)
{
	this->secondaryText = secondaryText;
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

	//Manually draw the lines utilising text
	for (int i = 0; i < lines.size(); i++)
	{
		RenderText(Vector2(StartingPos.Getx(), StartingPos.Gety() + i), lines.at(i));
	}
}
