#include "GameStateBattle.h"
#include "GameData.h"
#include "Item.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>


GameStateBattle::GameStateBattle(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();
	this->gameStateScreenSize = Vector2(110, 35);
	this->playerStatsPtr = gameData->GetPlayerStats();
	this->currentEvent = BATTLEEVENT::PLAYER_CHOICE;
	this->currentConsoleText = "";
	this->currentFrame = 0;
	this->currentItemSelected = 0;
}

void GameStateBattle::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);

	currentBattleData = gameData->GetCurrentBattleData();
	this->currentEvent = BATTLEEVENT::PLAYER_CHOICE;
	this->currentConsoleText = "";
	this->currentFrame = 0;
	this->currentItemSelected = 0;
}

void GameStateBattle::GetInputs()
{

	if (currentEvent == BATTLEEVENT::PLAYER_CHOICE) {
		ClearConsole();

		bool hasSelectedValidOption = false;
		do {
			int option = _getch();

			//ATTACK
			if (option == '1')
			{
				//SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM);
				// 
				// 
				//Calculate target damage
				int targetDamage = playerStatsPtr->GetBaseDamage() + playerStatsPtr->GetAttack();
				//Implement the damage to the enemy
				currentBattleData->GetFirstEnemy()->DamageEnemy(targetDamage);
				//Display text
				SetConsoleText("Enemy damaged by " + std::to_string(targetDamage));

				//If enemy is dead, go to game won state
				if (currentBattleData->GetFirstEnemy()->IsDead()) {
					SetBattleEvent(BATTLEEVENT::GAME_WON);
				}
				//If still alive, enemy will attack
				else {
					SetBattleEvent(BATTLEEVENT::ENEMY_ATTACK);
				}

				hasSelectedValidOption = true;
			}

			//ABILITIES
			else if (option == '2')
			{
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_ABILITIES);
				hasSelectedValidOption = true;
			}

			//ITEMS
			else if (option == '3')
			{
				this->currentItemSelected = 0;
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_ITEMS);
				hasSelectedValidOption = true;
			}

			//FLEE
			else if (option == '4')
			{
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_FLEE);
				SetConsoleText("Player Fled!");
				hasSelectedValidOption = true;
			}
		} while (!hasSelectedValidOption);
	}
	
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM) {

	}
	
	else if (currentEvent == BATTLEEVENT::ENEMY_ATTACK) {
		if (currentFrame == 1) {
			Sleep(1000);

			int targetDamage = currentBattleData->GetFirstEnemy()->GetAttack();
			playerStatsPtr->DamagePlayer(targetDamage);
			SetConsoleText("Player damaged by " + std::to_string(targetDamage));
		}
		else if (currentFrame == 2) {
			Sleep(1000);
			SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE);
			ClearConsole();
		}
	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ITEMS) {
		bool validOptionSelected = false;


		//ClearConsole();

		do {
			int option = _getch();

			if (option == 'a' || option == 'A') {
				currentItemSelected--;

				if (currentItemSelected < 0)
					currentItemSelected = gameData->GetInventorySize() - 1;

				validOptionSelected = true;
			}
			else if (option == 'd' || option == 'D') {
				currentItemSelected++;

				if (currentItemSelected >= gameData->GetInventorySize())
					currentItemSelected = 0;

				validOptionSelected = true;
			}
		} while (!validOptionSelected);
	}
	
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FLEE) {
		if (currentFrame == 1) {

			Sleep(1000);
		}
		else if (currentFrame == 2)
		{
			ClearConsole();
			currentBattleData->SetBattleEndState(BattleData::BATTLEEND::FLED);
			gameData->SetGameStateValue(GAMESTATEVALUE::WORLDSTATE);
		}
	}

	else if (currentEvent == BATTLEEVENT::GAME_WON) {
		if (currentFrame == 1) {
			SetConsoleText("Enemies have been defeated! Pedro is victorious!");
			Sleep(2000);
		}
		else if (currentFrame == 2) {
			Sleep(3000);
			ClearConsole();
			currentBattleData->SetBattleEndState(BattleData::BATTLEEND::WON);
			gameData->SetGameStateValue(GAMESTATEVALUE::WORLDSTATE);
		}
	}
	else {
		_getch();
	}

	currentFrame++;


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
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM)
	{

	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ABILITIES)
	{

	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ITEMS) 
	{
		Item currentItem = gameData->GetInventoryItem(currentItemSelected);
		
		std::string LeftArrow = R"(   __ 
  / / 
 / /  
 \ \  
  \_\ 
      )";
		screenPtr->RenderDrawing(Vector2(92, 29), LeftArrow);

		screenPtr->RenderText(Vector2(2, 30), std::to_string(currentItemSelected + 1) + " / " + std::to_string(gameData->GetInventorySize()));
		screenPtr->RenderText(Vector2(9, 30), currentItem.GetItemName());
		screenPtr->RenderText(Vector2(2, 31), currentItem.GetDescription());

		std::string RightArrow = R"( __   
 \ \  
  \ \ 
  / / 
 /_/
	)";
		screenPtr->RenderDrawing(Vector2(102, 29), RightArrow);

	}
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FLEE)
	{

	}
	else if (currentEvent == BATTLEEVENT::ENEMY_ATTACK)
	{

	}


	screenPtr->RenderText(Vector2(3, 30), GetConsoleText());








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

void GameStateBattle::SetBattleEvent(BATTLEEVENT targetEvent)
{
	currentFrame = 0;
	currentEvent = targetEvent;
}

void GameStateBattle::SetConsoleText(std::string targetText)
{
	currentConsoleText = targetText;
}

void GameStateBattle::ClearConsole()
{
	currentConsoleText = "";
}

std::string GameStateBattle::GetConsoleText()
{
	return currentConsoleText;
}
