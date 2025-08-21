#include "GameStateBattle.h"
#include "GameData.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <sstream>


GameStateBattle::GameStateBattle(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();
	this->gameStateScreenSize = Vector2(110, 35);
	this->playerStatsPtr = gameData->GetPlayerStats();
	this->currentEvent = BATTLEEVENT::PLAYER_CHOICE;
	this->currentConsoleText = "";
}

void GameStateBattle::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);

	currentBattleData = gameData->GetCurrentBattleData();
}

void GameStateBattle::GetInputs()
{
	if (currentEvent == BATTLEEVENT::PLAYER_CHOICE) {

		int option = _getch();
		if (option == '1')
		{
			currentEvent = BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM;


			int targetDamage = playerStatsPtr->GetBaseDamage();// + playerStatsPtr->GetAttack();
			currentBattleData->GetFirstEnemy()->DamageEnemy(targetDamage);
			int x = targetDamage;

			SetConsoleText("Enemy damaged by " + std::to_string(targetDamage));


			currentEvent = BATTLEEVENT::ENEMY_ATTACK;

		}
		else if (option == '2')
		{
			currentEvent = BATTLEEVENT::PLAYER_CHOICE_ABILITIES;
		}
		else if (option == '3')
		{
			currentEvent = BATTLEEVENT::PLAYER_CHOICE_ITEMS;
		}
		else if (option == '4')
		{
			currentEvent = BATTLEEVENT::PLAYER_CHOICE_FLEE;
		}
	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM) {
	}
	else {
		_getch();
	}


	//_getch();
}

void GameStateBattle::RenderObjects()
{
}

void GameStateBattle::RenderUI()
{
	Vector2 screenSize = screenPtr->GetScreenSize();

	for (int i = 0; i < screenSize.Getx(); i++)
		screenPtr->RenderCharacter('_', i, 28);

	if (currentEvent == BATTLEEVENT::PLAYER_CHOICE)
	{
		const int optionBoxLength = 11;
		// Attack
		for (int i = 34; i < 34 + optionBoxLength; i++)
			screenPtr->RenderCharacter('-', i, 29);
		screenPtr->RenderCharacter('|', 33, 29 + 1);
		screenPtr->RenderText(Vector2(35, 30), "1:ATTACK");
		screenPtr->RenderCharacter('|', 45, 29 + 1);
		for (int i = 34; i < 34 + optionBoxLength; i++)
			screenPtr->RenderCharacter('-', i, 31);

		// Item
		for (int i = 34; i < 34 + optionBoxLength; i++)
			screenPtr->RenderCharacter('-', i, 32);
		screenPtr->RenderCharacter('|', 33, 32 + 1);
		screenPtr->RenderText(Vector2(35, 33), "3:ITEM");
		screenPtr->RenderCharacter('|', 45, 32 + 1);
		for (int i = 34; i < 34 + optionBoxLength; i++)
			screenPtr->RenderCharacter('-', i, 34);

		// Ability
		for (int i = 65; i < 65 + optionBoxLength; i++)
			screenPtr->RenderCharacter('-', i, 29);
		screenPtr->RenderCharacter('|', 64, 29 + 1);
		screenPtr->RenderText(Vector2(66, 30), "2:ABILITY");
		screenPtr->RenderCharacter('|', 76, 29 + 1);
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
	}
	//else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_SELECTENEMY)
	//{
	//	screenPtr->RenderText(Vector2(66, 33), "this is player selection which enemy");
	//}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM)
	{
		screenPtr->RenderText(Vector2(66, 33), GetConsoleText());
	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ABILITIES)
	{
		//screenPtr->RenderText(Vector2(66, 33), "this is ability option");
	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ITEMS) 
	{
		//screenPtr->RenderText(Vector2(66, 33), "this is items option");
	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FLEE)
	{
		//screenPtr->RenderText(Vector2(66, 33), "this is flee option");
	}
	else if (currentEvent == BATTLEEVENT::ENEMY_ATTACK)
	{
		screenPtr->RenderText(Vector2(66, 33), GetConsoleText());
	}










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

	//-----------------------------------------------------------------------------------------------

	// Mutant Stats bar
	for (int i = 7; i < 23; i++)
		screenPtr->RenderCharacter('-', i, 18);
	for (int i = 19; i < 22; i++)
		screenPtr->RenderCharacter('|', 6, i);
	for (int i = 19; i < 22; i++)
		screenPtr->RenderCharacter('|', 23, i);
	for (int i = 7; i < 23; i++)
		screenPtr->RenderCharacter('-', i, 22);

	screenPtr->RenderText(Vector2(9, 19), "Mutant");
	screenPtr->RenderText(Vector2(9, 20), "Hp:  " + std::to_string(currentBattleData->GetFirstEnemy()->GetHealth()) + " / " + std::to_string(currentBattleData->GetFirstEnemy()->GetMaxHealth()));
	screenPtr->RenderText(Vector2(9, 21), "Atk: " + std::to_string(currentBattleData->GetFirstEnemy()->GetAttack()));
	screenPtr->RenderText(Vector2(6, 23), "ABT: 25% Chance to");
	screenPtr->RenderText(Vector2(6, 24), "poison the player");
	

	if (!currentBattleData->IsSingleBattle())
	{
		// Healer Stats bar
		for (int i = 38; i < 54; i++)
			screenPtr->RenderCharacter('-', i, 18);
		for (int i = 19; i < 22; i++)
			screenPtr->RenderCharacter('|', 37, i);
		for (int i = 19; i < 22; i++)
			screenPtr->RenderCharacter('|', 54, i);
		for (int i = 38; i < 54; i++)
			screenPtr->RenderCharacter('-', i, 22);

		screenPtr->RenderText(Vector2(40, 19), "Healer");
		screenPtr->RenderText(Vector2(40, 20), "Hp:  " + std::to_string(currentBattleData->GetSecondEnemy()->GetHealth()) + " / " + std::to_string(currentBattleData->GetFirstEnemy()->GetMaxHealth()));
		screenPtr->RenderText(Vector2(40, 21), "Atk: " + std::to_string(currentBattleData->GetSecondEnemy()->GetAttack()));
		screenPtr->RenderText(Vector2(37, 23), "ABT: Heals 3 hp to lowest");
		screenPtr->RenderText(Vector2(37, 24), "enemy hp every turn");
	}

}

GAMESTATEVALUE GameStateBattle::GetGameStateValue()
{
	return GAMESTATEVALUE::BATTLESTATE;
}

void GameStateBattle::SetConsoleText(std::string targetText)
{
	currentConsoleText = targetText;
}

std::string GameStateBattle::GetConsoleText()
{
	return currentConsoleText;
}
