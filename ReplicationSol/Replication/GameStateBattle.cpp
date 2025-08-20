#include "GameStateBattle.h"
#include <conio.h>
#include <iostream>

GameStateBattle::GameStateBattle(Screen* screenPtr)
{
	this->screenPtr = screenPtr;
	this->gameStateScreenSize = Vector2(110, 35);
}

void GameStateBattle::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);
}

void GameStateBattle::GetInputs()
{
	_getch();
}

void GameStateBattle::RenderObjects()
{
}

void GameStateBattle::RenderUI()
{
	Vector2 screenSize = screenPtr->GetScreenSize();

	const int optionBoxLength = 11;

	for (int i = 0; i < screenSize.Getx(); i++)
		screenPtr->RenderCharacter('_', i, 28);
	// Attack
	for (int i = 38; i < 38 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 29);
	screenPtr->RenderCharacter('|', 37, 29+1);
	screenPtr->RenderText(Vector2(39, 30), "1:ATTACK");
	screenPtr->RenderCharacter('|', 49, 29+1);
	for (int i = 38; i < 38 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 31);

	// Item
	for (int i = 38; i < 38 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 32);
	screenPtr->RenderCharacter('|', 37, 32+1);
	screenPtr->RenderText(Vector2(39, 33), "3:ITEM");
	screenPtr->RenderCharacter('|', 49, 32+1);
	for (int i = 38; i < 38 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 34);

	// Ability
	for (int i = 72; i < 72 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 29);
	screenPtr->RenderCharacter('|', 71, 29+1);
	screenPtr->RenderText(Vector2(73, 30), "2:ABILITY");
	screenPtr->RenderCharacter('|', 83, 29+1);
	for (int i = 72; i < 72 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 31);

	// Flee
	for (int i = 72; i < 72 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 32);
	screenPtr->RenderCharacter('|', 71, 32 + 1);
	screenPtr->RenderText(Vector2(73, 33), "4:FLEE");
	screenPtr->RenderCharacter('|', 83, 32 + 1);
	for (int i = 72; i < 72 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 34);

	// Player Health bar
	for (int i = 80; i < 110; i++)
		screenPtr->RenderCharacter('-', i, 24);
	for (int i = 25; i < 28; i++)
		screenPtr->RenderCharacter('|', 80, i);
	screenPtr->RenderText(Vector2(87, 25), "Health: ");
	screenPtr->RenderText(Vector2(87, 26), "Attack: ");
	screenPtr->RenderText(Vector2(87, 27), "Defense: ");


	std::string pedro = 
		
		
R"(
         ###+++++++++++++++###       
  #### ###+++++++++++++++++++###     
 ##+--##+++++++++++++++++++++++##    
 #-+#++#++++++++++++++++++++++++##   
 #++-+-#+++++++++++++++++++++++++##  
 #++##-#+++++++++++++++++++++++++##  
  #--+#++++++++++++++++++++++++++##  
  ####+++++++++++++++++++++++######  
  #############################++##  
  ########################++++#++### 
##++++##+##+++++###+##++++##+#++++++#
##+++++###++++++++++#+++++++###+++++#
##+++++##+++++++++#+#++++++++##++++##
 ######++##++++++#+++##++++##+++###  
    #++++++++###++++++++++++++++++#  
     ##          ###+#+         ##   
     ###     ####++++++# ###   ##    
       ##   #+##++++++++##+#  ##     
        #####+##++++++++##+# ##      
          #######++++++#  ####       
            ##  #+++++## ####
              ###########)";



	screenPtr->RenderDrawing(Vector2(0, 0), pedro);
}
