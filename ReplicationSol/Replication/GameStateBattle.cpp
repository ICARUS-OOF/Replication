#include "GameStateBattle.h"
#include "GameData.h"
#include <conio.h>
#include <iostream>
#include <string>

GameStateBattle::GameStateBattle(Screen* screenPtr, PlayerStats* playerStatsPtr, GAMESTATEVALUE* gameStateValuePtr, GameData* gameData)
{
	this->screenPtr = screenPtr;
	this->gameStateScreenSize = Vector2(110, 35);
	this->playerStatsPtr = playerStatsPtr;
	this->gameStateValuePtr = gameStateValuePtr;
	this->gameData = gameData;
}

void GameStateBattle::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);

	currentBattleData = gameData->GetCurrentBattleData();
}

void GameStateBattle::GetInputs()
{
	int option = _getch();
	switch (option)
	{
	//Attack
	case '1':

		break;

	//Abilities
	case '2':

		break;

	//Items
	case '3':

		break;

	//Flee
	case '4':

		break;



	default:
		break;
	}
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
	for (int i = 34; i < 34 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 29);
	screenPtr->RenderCharacter('|', 33, 29+1);
	screenPtr->RenderText(Vector2(35, 30), "1:ATTACK");
	screenPtr->RenderCharacter('|', 45, 29+1);
	for (int i = 34; i < 34 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 31);

	// Item
	for (int i = 34; i < 34 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 32);
	screenPtr->RenderCharacter('|', 33, 32+1);
	screenPtr->RenderText(Vector2(35, 33), "3:ITEM");
	screenPtr->RenderCharacter('|', 45, 32+1);
	for (int i = 34; i < 34 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 34);

	// Ability
	for (int i = 65; i < 65 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 29);
	screenPtr->RenderCharacter('|', 64, 29+1);
	screenPtr->RenderText(Vector2(66, 30), "2:ABILITY");
	screenPtr->RenderCharacter('|', 76, 29+1);
	for (int i = 65; i < 65 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 31);

	// Flee
	for (int i = 65; i < 65 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 32);
	screenPtr->RenderCharacter('|', 64, 32 + 1);
	screenPtr->RenderText(Vector2(66, 33), "4:FLEE");
	screenPtr->RenderCharacter('|', 76, 32 + 1);
	for (int i = 65; i < 65 + optionBoxLength; i++)
		screenPtr->RenderCharacter('-', i, 34);

	// Player Stats bar
	for (int i = 80; i < 110; i++)
		screenPtr->RenderCharacter('-', i, 24);
	for (int i = 25; i < 28; i++)
		screenPtr->RenderCharacter('|', 80, i);
	screenPtr->RenderText(Vector2(87, 25), "Health:  " + std::to_string(playerStatsPtr->GetHealth()) + " / " + std::to_string(playerStatsPtr->GetMaxHealth()));
	screenPtr->RenderText(Vector2(87, 26), "Attack:  " + std::to_string(playerStatsPtr->GetAttack()));
	screenPtr->RenderText(Vector2(87, 27), "Defense: " + std::to_string(playerStatsPtr->GetDefence()));

	//JUNSHEN - Pedro DISPLAY ASCII Art
	{
		bool isHurt = false;
		isHurt = true;
		std::string pedro =


			R"(
                         ##
      ####################
    ########################
    #########################
   ###########################
   ###########################
 #############################
 #############################
##########....####.....##########
#....##..######..#######..##....#
#.....#.....#....#..#.....#.....#
#.....#.....#..#....#.....#.....#
###...#........##.........#...###
    ###...................###
      #...................#  
      ###......###......###
       ####.#.......#.####
            #########  )";



		std::string pedrohurt =


			R"(
                         ##    
         ##################    
    ########################
    #########################
   ###########################
   ###########################
 #############################
 #############################
##########..######..#..##########
#....##..####....#..####..##....#
#.....###.....#..##.....###.....#
#.....###..#...#.....#..###.....#
###...##.......##........##...###
    ###...................###    
      #.......##..........#      
      ###...###..##.....###      
       #####.##..#..#.####       
            #########   )";


		if (isHurt == true)
		{
			screenPtr->RenderDrawing(Vector2(75, 3), pedrohurt);

		}
		else
			screenPtr->RenderDrawing(Vector2(75, 3), pedro);
	}
}

GAMESTATEVALUE GameStateBattle::GetGameStateValue()
{
	return GAMESTATEVALUE::BATTLESTATE;
}
