#include "GameStateBattle.h"
#include "GameData.h"
#include "Item.h"
#include "ItemUsage.h"
#include "EnemyData.h"
#include "MusicHandler.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>


/// <summary>
/// KAYDEN 
/// 
/// Constructor which INSITIALISE varibles which are in gamedata
/// </summary>
/// <param name="gameData"></param>
GameStateBattle::GameStateBattle(GameData* gameData)
{
	this->gameData = gameData;
	this->currentBattleData = nullptr;
	this->screenPtr = gameData->GetScreenPtr();
	this->gameStateScreenSize = Vector2(110, 35);
	this->playerStatsPtr = gameData->GetPlayerStats();
	this->currentEvent = BATTLEEVENT::PLAYER_CHOICE;
	this->currentConsoleText = "";
	this->currentItemSelected = 0;
	this->currentAbilitySelected = 0;
	this->abilities_poisonTurnsLeft = -1;
	this->abilities_armourTurnsLeft = -1;
	this->abilities_hasUsedRestore = false;
	this->isEnemyGuarding = false;
	this->poisonHitPlayer = false;
	this->turnNumber = 0;
	this->selectedEnemy = 0;
	this->bossAdditionDamage = 0;
	this->itemUsages.clear();

	this->playerFrames_damaged = std::vector<std::string>(0);

	SetBattleAnimations();
}

/// <summary>
/// KAYDEN
/// 
/// Reset the varibles
/// </summary>
void GameStateBattle::OnStateEnter()
{
	this->currentEvent = BATTLEEVENT::PLAYER_CHOICE;
	this->currentConsoleText = "";
	this->currentItemSelected = 0;
	this->currentAbilitySelected = 0;
	this->currentBattleData = gameData->GetCurrentBattleData();
	this->turnNumber = 0;
	this->selectedEnemy = 0;
	this->bossAdditionDamage = 0;

	currentPlayerFrame = playerFrame_idle;

	this->abilities_poisonTurnsLeft = -1;
	this->abilities_armourTurnsLeft = -1;
	this->abilities_hasUsedRestore = false;
	this->isEnemyGuarding = false;
	this->poisonHitPlayer = false;


	gameData->AddAbility(EnemyData::ENEMYTYPE::MUTANT);
	//gameData->AddAbility(EnemyData::ENEMYTYPE::HEALER);
	//gameData->AddAbility(EnemyData::ENEMYTYPE::GUARD);

	gameData->GetPlayerStats()->ResetStats();
	this->itemUsages.clear();

	// reset the health of the first or second enemy depending on if its single or double enemy
	currentBattleData->GetFirstEnemy()->ResetEnemyHealth();
	if (currentBattleData->IsDoubleBattle())
		currentBattleData->GetSecondEnemy()->ResetEnemyHealth();
	

	// check if it boss enemy then play boss music if not, play normal enemy music
	if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::BOSS)
		MusicHandler::PlayMusic("04_Nikolai");
	else
		MusicHandler::PlayMusic("03_Replicants");

	//Set the screen size and render screen
	screenPtr->ResizeScreen(gameStateScreenSize);
	ClearScreen();
	this->RenderScreen();
}

/// <summary>
/// AHMAD
/// 
/// The main loop that runs he battle with player actions and enemy attacking
/// </summary>
void GameStateBattle::Loop()
{
	currentPlayerFrame = playerFrame_idle;

	//----PLAYER CHOICE----
	if (currentEvent == BATTLEEVENT::PLAYER_CHOICE) {
		ClearConsole();

		bool hasSelectedValidOption = false;
		do {
			int option = _getch();

			//ATTACK
			if (option == '1')
			{
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_FIGHT_SELECTENEMY);
				hasSelectedValidOption = true;
			}

			//ABILITIES
			else if (option == '2')
			{
				currentAbilitySelected = 0;
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


	//----SELECT ENEMY
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_SELECTENEMY) {

		screenPtr->RenderText(Vector2(2, 29), "Press 'ESC' to go back");
		screenPtr->RenderText(Vector2(2, 31), "Select an enemy to attack... (Press the corresponding number)");
		if (!currentBattleData->GetFirstEnemy()->IsDead())
			screenPtr->RenderText(Vector2(2, 33), "1. " + currentBattleData->GetFirstEnemy()->GetEnemyName());
		if (currentBattleData->IsDoubleBattle() && !currentBattleData->GetSecondEnemy()->IsDead())
			screenPtr->RenderText(Vector2(15, 33), "2. " + currentBattleData->GetSecondEnemy()->GetEnemyName());
		this->RenderScreen();


		bool hasSelectedValidOption = false;
		do {
			int option = _getch();

			switch (option)
			{
			case '1':
				if (!currentBattleData->GetFirstEnemy()->IsDead()) {
					SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM);
					this->selectedEnemy = 1;
					hasSelectedValidOption = true;
				}
				break;

			case '2':
				if (currentBattleData->IsDoubleBattle() && !currentBattleData->GetSecondEnemy()->IsDead()) {
					SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM);
					this->selectedEnemy = 2;
					hasSelectedValidOption = true;
				}
				break;


			case 27:
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE);
				hasSelectedValidOption = true;
				break;

			default:
				break;
			}
		} while (!hasSelectedValidOption);



	}

	//---PLAYER FIGHT ANIMATION
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM) {

		PlayAnimationSet(playerFrames_fight, true);

		//Calculate target damage
		int targetDamage = playerStatsPtr->GetBaseDamage() + playerStatsPtr->GetAttack();

		if (isEnemyGuarding) {
			targetDamage -= enemyArmourWeight;
		}

		if (targetDamage < 0)
			targetDamage = 0;

		bool isWon = false;




		if (selectedEnemy == 1) {
			PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_damaged, true);

			if (currentBattleData->GetFirstEnemy()->GetHealth() - targetDamage <= 0)
				PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_death, false);

			//Implement the damage to the enemy
			currentBattleData->GetFirstEnemy()->DamageEnemy(targetDamage);

			bool winPreventedBySecondEnemy = false;
			if (currentBattleData->IsDoubleBattle() && !currentBattleData->GetSecondEnemy()->IsDead())
				winPreventedBySecondEnemy = true;

			if (currentBattleData->GetFirstEnemy()->IsDead())
				PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_death, true);

			//If enemy is dead, go to game won state
			if (currentBattleData->GetFirstEnemy()->IsDead() && !winPreventedBySecondEnemy) {
				isWon = true;
			}
			//If still alive, enemy will attack
			else {
				SetBattleEvent(BATTLEEVENT::ENEMY_ATTACK);
			}
		}
		else if (selectedEnemy == 2) {
			PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_damaged, true);

			if (currentBattleData->GetSecondEnemy()->GetHealth() - targetDamage <= 0)
				PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_death, false);

			//Implement the damage to the enemy
			currentBattleData->GetSecondEnemy()->DamageEnemy(targetDamage);

			bool winPreventedByFirstEnemy = false;
			if (currentBattleData->IsDoubleBattle() && !currentBattleData->GetFirstEnemy()->IsDead())
				winPreventedByFirstEnemy = true;

			if (currentBattleData->GetSecondEnemy()->IsDead())
				PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_death, true);

			//If enemy is dead, go to game won state
			if (currentBattleData->GetSecondEnemy()->IsDead() && !winPreventedByFirstEnemy) {
				isWon = true;
			}
			//If still alive, enemy will attack
			else {
				SetBattleEvent(BATTLEEVENT::ENEMY_ATTACK);
			}
		}


		std::string enemyThatWasAttackedName;
		if (selectedEnemy == 1) enemyThatWasAttackedName = currentBattleData->GetFirstEnemy()->GetEnemyName();
		else if (selectedEnemy == 2) enemyThatWasAttackedName = currentBattleData->GetSecondEnemy()->GetEnemyName();

		screenPtr->RenderText(Vector2(3, 30), enemyThatWasAttackedName + " was damaged by " + std::to_string(targetDamage));

		this->RenderScreen();

		Sleep(2000);

		if (isWon)
			SetBattleEvent(BATTLEEVENT::GAME_WON);
		else
			SetBattleEvent(BATTLEEVENT::ENEMY_ATTACK);
	}

	///-------ENEMY ATTACKING------
	else if (currentEvent == BATTLEEVENT::ENEMY_ATTACK) {
		/*
		{
			system("cls");
			for (int i = 0; i < itemUsages.size(); i++)
			{
				std::cout << itemUsages[i].GetItem().GetItemName() << ": " << itemUsages[i].GetUsageLeft() << std::endl;
			}
		}*/
			

		UpdateItemUsages();
		UpdateAbilitiesUsage();


		//-----POISONING THE ENEMY----
		if (abilities_poisonTurnsLeft > 0) {
			if (currentBattleData->GetFirstEnemy()->IsAlive() && currentBattleData->GetFirstEnemy()->GetHealth() - poisonWeight > 0) {
				PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_damaged, true);
				PlayAnimationSet(playerFrames_poisoned, true);
				currentBattleData->GetFirstEnemy()->DamageEnemy(poisonWeight);

				SetConsoleText("Player's poison damaged " + currentBattleData->GetFirstEnemy()->GetEnemyName() + " by " + std::to_string(poisonWeight));
				this->RenderScreen();
				Sleep(2000);
			}

			if (currentBattleData->IsDoubleBattle()) {
				if (currentBattleData->GetSecondEnemy()->IsAlive() && currentBattleData->GetSecondEnemy()->GetHealth() - poisonWeight > 0) {
					PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_damaged, true);
					PlayAnimationSet(playerFrames_poisoned, true);

					currentBattleData->GetSecondEnemy()->DamageEnemy(poisonWeight);

					SetConsoleText("Player's poison damaged " + currentBattleData->GetSecondEnemy()->GetEnemyName() + " by " + std::to_string(poisonWeight));
					this->RenderScreen();
					Sleep(2000);
				}
			}
		}




		//-----DAMAGING PLAYER----

		if (currentBattleData->GetFirstEnemy()->IsAlive()) {

			PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_attack, true);
			PlayAnimationSet(playerFrames_damaged, true);

			int targetDamage = currentBattleData->GetFirstEnemy()->GetAttack() - gameData->GetPlayerStats()->GetDefence();
			if (targetDamage <= 0)
				targetDamage = 0;
			
			if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::BOSS) {
				targetDamage += bossAdditionDamage;
			}

			playerStatsPtr->DamagePlayer(targetDamage);
			SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " damaged player by " + std::to_string(targetDamage));
			this->RenderScreen();
			Sleep(2000);
		}

		if (currentBattleData->IsDoubleBattle() && currentBattleData->GetSecondEnemy()->IsAlive()) {
			PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_attack, true);
			PlayAnimationSet(playerFrames_damaged, true);

			int targetDamage = currentBattleData->GetSecondEnemy()->GetAttack() - gameData->GetPlayerStats()->GetDefence();
			if (targetDamage <= 0)
				targetDamage = 0;
			playerStatsPtr->DamagePlayer(targetDamage);
			SetConsoleText(currentBattleData->GetSecondEnemy()->GetEnemyName() + " damaged player by " + std::to_string(targetDamage));
			this->RenderScreen();
			Sleep(2000);
		}


		//-----------ENEMY ABILITIES--------
		if (turnNumber > 0) {
			//--------POISON-------
			if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::MUTANT && currentBattleData->GetFirstEnemy()->IsAlive()) {
				if (gameData->GetPlayerStats()->GetHealth() - enemyPoisonWeight > 0) {
					PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
					gameData->GetPlayerStats()->DamagePlayer(enemyPoisonWeight);

					poisonHitPlayer = true;
					SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " poisoned the player by " + std::to_string(enemyPoisonWeight));
					this->RenderScreen();
					Sleep(2000);
				}


			}
			if (currentBattleData->IsDoubleBattle() && currentBattleData->GetSecondEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::MUTANT && currentBattleData->GetSecondEnemy()->IsAlive()) {
				if (gameData->GetPlayerStats()->GetHealth() - enemyPoisonWeight > 0) {
					PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_ability, true);
					gameData->GetPlayerStats()->DamagePlayer(enemyPoisonWeight);

					poisonHitPlayer = true;
					SetConsoleText(currentBattleData->GetSecondEnemy()->GetEnemyName() + " poisoned the player by " + std::to_string(enemyPoisonWeight));
					this->RenderScreen();
					Sleep(2000);
				}
			}

			


			//---------HEALING---------
			if (currentBattleData->IsSingleBattle()) {
				if (currentBattleData->GetFirstEnemy()->GetHealth() < currentBattleData->GetFirstEnemy()->GetMaxHealth() && 
					currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::HEALER &&
					currentBattleData->GetFirstEnemy()->IsAlive()) {

					PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
					currentBattleData->GetFirstEnemy()->HealEnemy(enemyHealWeight);

					SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " healed themselves by " + std::to_string(enemyHealWeight));
					this->RenderScreen();
					Sleep(2000);
				}
			}
			else {

				EnemyData* healEnemySource = nullptr;

				if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::HEALER && currentBattleData->GetFirstEnemy()->IsAlive())
					healEnemySource = currentBattleData->GetFirstEnemy();
				else if (currentBattleData->GetSecondEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::HEALER && currentBattleData->GetSecondEnemy()->IsAlive())
					healEnemySource = currentBattleData->GetSecondEnemy();



				if (healEnemySource != nullptr) {
					//Heal first enemy
					if (currentBattleData->GetFirstEnemy()->GetHealth() < currentBattleData->GetSecondEnemy()->GetHealth() && currentBattleData->GetFirstEnemy()->IsAlive()) {
						PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
						currentBattleData->GetFirstEnemy()->HealEnemy(enemyHealWeight);


						SetConsoleText(healEnemySource->GetEnemyName() + " healed " + currentBattleData->GetFirstEnemy()->GetEnemyName() + " by " + std::to_string(enemyHealWeight));
						this->RenderScreen();
						Sleep(2000);
					}
					//Heal second enemy
					else if (currentBattleData->GetSecondEnemy()->IsAlive() ){
						PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_ability, true);
						currentBattleData->GetSecondEnemy()->HealEnemy(enemyHealWeight);

						SetConsoleText(healEnemySource->GetEnemyName() + " healed " + currentBattleData->GetSecondEnemy()->GetEnemyName() + " by " + std::to_string(enemyHealWeight));
						this->RenderScreen();
						Sleep(2000);
					}
				}
			}



			//---------DEFENCE-------------
			if (currentBattleData->IsSingleBattle()) {
				if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::GUARD) {

					isEnemyGuarding = !isEnemyGuarding;

					if (isEnemyGuarding) {
						PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
						SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " guards!");
						this->RenderScreen();
						Sleep(2000);
					}
					else {
						PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
						SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " put their guard down!");
						this->RenderScreen();
						Sleep(2000);
					}
				}
			}
			else {
				if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::GUARD && currentBattleData->GetFirstEnemy()->IsAlive()) {

					isEnemyGuarding = !isEnemyGuarding;

					if (isEnemyGuarding) {
						PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
						SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " guards!");
						this->RenderScreen();
						Sleep(2000);
					}
					else {
						PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
						SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " put their guard down!");
						this->RenderScreen();
						Sleep(2000);
					}
				}
				else if (currentBattleData->GetSecondEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::GUARD && currentBattleData->GetSecondEnemy()->IsAlive()) {
					isEnemyGuarding = !isEnemyGuarding;

					if (isEnemyGuarding) {
						PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_ability, true);
						SetConsoleText(currentBattleData->GetSecondEnemy()->GetEnemyName() + " guards!");
						this->RenderScreen();
						Sleep(2000);
					}
					else {
						PlayEnemyAnimationSet(currentBattleData->GetSecondEnemy(), currentBattleData->GetSecondEnemy()->enemyFrames_ability, true);
						SetConsoleText(currentBattleData->GetSecondEnemy()->GetEnemyName() + " put their guard down!");
						this->RenderScreen();
						Sleep(2000);
					}
				}
			}





			//---------DAMAGE STACKING FOR BOSS--------
			if (currentBattleData->GetFirstEnemy()->GetEnemyType() == EnemyData::ENEMYTYPE::BOSS) {
				bossAdditionDamage++;
				PlayEnemyAnimationSet(currentBattleData->GetFirstEnemy(), currentBattleData->GetFirstEnemy()->enemyFrames_ability, true);
				SetConsoleText(currentBattleData->GetFirstEnemy()->GetEnemyName() + " strengthens himself by 1!");
				this->RenderScreen();
				Sleep(2000);
			}

		}





		if (gameData->GetPlayerStats()->GetHealth() <= 0)
		{
			SetBattleEvent(BATTLEEVENT::PLAYER_DEATH);
			return;
		}

		this->RenderScreen();

		turnNumber++;
		SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE);
		ClearConsole();
	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ABILITIES) {
		
		bool validOptionSelected = false;


		do {
			int option = _getch();

			if (option == 'a' || option == 'A') {
				currentAbilitySelected--;

				if (currentAbilitySelected < 0)
					currentAbilitySelected = gameData->GetAbilities().size() - 1;

				validOptionSelected = true;
			}
			else if (option == 'd' || option == 'D') {
				currentAbilitySelected++;

				if (currentAbilitySelected >= gameData->GetAbilities().size())
					currentAbilitySelected = 0;

				validOptionSelected = true;
			}
			else if (option == 27) {
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE);
				validOptionSelected = true;
			}

			//----------USE ABILITY----------
			else if (option == ' ')
			{
				if (gameData->GetAbilities().size() > 0) {
					EnemyData::ENEMYTYPE abilityType = gameData->GetAbilities()[currentAbilitySelected];

					//POISON
					if (abilityType == EnemyData::ENEMYTYPE::MUTANT && abilities_poisonTurnsLeft == -1)
					{
						SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_ABILITIES_USAGE);
						SetConsoleText("Pedro used " + EnemyData::EnemyTypeToAbilityString(gameData->GetAbilities()[currentAbilitySelected]));

						bool usePoison = gameData->RollDice(100);

						if (usePoison) {
							SetConsoleText("Poison is Successfully applied");
							abilities_poisonTurnsLeft = 4;
						}
						else {
							SetConsoleText("Poison is Unsuccessful");
						}

						validOptionSelected = true;
					}

					//RESTORE
					else if (abilityType == EnemyData::ENEMYTYPE::HEALER && !abilities_hasUsedRestore)
					{
						SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_ABILITIES_USAGE);
						SetConsoleText("Pedro used " + EnemyData::EnemyTypeToAbilityString(gameData->GetAbilities()[currentAbilitySelected]));

						gameData->GetPlayerStats()->HealPlayer(6);
						abilities_hasUsedRestore = true;

						validOptionSelected = true;
					}

					//ARMOUR
					else if (abilityType == EnemyData::ENEMYTYPE::GUARD && abilities_armourTurnsLeft == -1)
					{
						SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_ABILITIES_USAGE);
						SetConsoleText("Pedro used " + EnemyData::EnemyTypeToAbilityString(gameData->GetAbilities()[currentAbilitySelected]));

						gameData->GetPlayerStats()->AddDefence(armourWeight);
						abilities_armourTurnsLeft = 2;

						validOptionSelected = true;
					}
				}
			}
		} while (!validOptionSelected);
	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ABILITIES_USAGE) {
		PlayAnimationSet(playerFrames_abilities, true);

		Sleep(1000);
		SetBattleEvent(BATTLEEVENT::ENEMY_ATTACK);

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
			else if (option == 27) {
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE);
				validOptionSelected = true;
			}

			//----------USE ITEM----------
			else if (option == ' ' && gameData->GetInventory().size() > 0 )
			{
				lastItemUsed = gameData->GetInventoryItem(currentItemSelected);
				ApplyItemUsage(lastItemUsed);
				itemUsages.push_back(ItemUsage(lastItemUsed, lastItemUsed.GetUsesLeft()));
				gameData->RemoveItem(gameData->GetInventoryItem(currentItemSelected).GetItemName());
				SetBattleEvent(BATTLEEVENT::PLAYER_CHOICE_ITEMS_USAGE);
				validOptionSelected = true;
			}
		} while (!validOptionSelected);
	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ITEMS_USAGE) {

		PlayAnimationSet(playerFrames_items, true);

		SetConsoleText("Player used item: " + lastItemUsed.GetItemName());

		this->RenderScreen();

		Sleep(2000);
		SetBattleEvent(BATTLEEVENT::ENEMY_ATTACK);

	}
	
	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FLEE) {
		PlayAnimationSet(playerFrames_flee, false);

		Sleep(1000);

		this->RenderScreen();

		ClearConsole();
		currentBattleData->SetBattleEndState(BattleData::BATTLEEND::FLED);
		gameData->SetGameStateValue(GAMESTATEVALUE::WORLDSTATE);
	}

	else if (currentEvent == BATTLEEVENT::PLAYER_DEATH) {
		PlayAnimationSet(playerFrames_death, false);
		
		gameData->hasLost = true;

		MusicHandler::StopMusic();

		SetConsoleText("Player is Dead!");
		
		this->RenderScreen();

		Sleep(2000);


		ClearConsole();
		gameData->SetGameStateValue(GAMESTATEVALUE::ENDSTATE);

	}

	else if (currentEvent == BATTLEEVENT::GAME_WON) {
		SetConsoleText("Enemies have been defeated! Pedro is victorious!");
		MusicHandler::StopMusic();
		this->RenderScreen();
		Sleep(2000);

		//-----REWARDS----
		gameData->AddGcoins(currentBattleData->GetGCoinsReward());
		SetConsoleText("Player has gained " + std::to_string(currentBattleData->GetGCoinsReward()) + " GCoins!");
		this->RenderScreen();
		Sleep(2000);


		//-------ABILITY GAINING--------
		if (!gameData->HasAbility(currentBattleData->GetFirstEnemy()->GetEnemyType()) && 
			currentBattleData->GetFirstEnemy()->GetEnemyType() != EnemyData::ENEMYTYPE::BOSS) {

			gameData->AddAbility(currentBattleData->GetFirstEnemy()->GetEnemyType());
			ClearConsole();
			SetConsoleText("You have obtained a ability: " + EnemyData::EnemyTypeToAbilityString(currentBattleData->GetFirstEnemy()->GetEnemyType()));
			this->RenderScreen();
			Sleep(2000);
		}
		if (currentBattleData->IsDoubleBattle()) {
			if (!gameData->HasAbility(currentBattleData->GetSecondEnemy()->GetEnemyType())) {
				gameData->AddAbility(currentBattleData->GetSecondEnemy()->GetEnemyType());
				ClearConsole();
				SetConsoleText("You have obtained a skill: " + EnemyData::EnemyTypeToAbilityString(currentBattleData->GetSecondEnemy()->GetEnemyType()));
				this->RenderScreen();
				Sleep(2000);
			}
		}


		currentBattleData->SetBattleEndState(BattleData::BATTLEEND::WON);
		gameData->SetGameStateValue(GAMESTATEVALUE::WORLDSTATE);
	}

	else {
		_getch();
	}

	this->RenderScreen();


	//_getch();
}

void GameStateBattle::RenderBaseObjects()
{
}


/// <summary>
/// AHMAD
/// 
/// Renders the ui for the battle actions 
/// </summary>
void GameStateBattle::RenderBaseUI()
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

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FIGHT_ANIM)
	{

	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ABILITIES)
	{
		if (gameData->GetAbilities().size() > 0) {

			screenPtr->RenderText(Vector2(2, 29), "Press 'ESC' to go back");
			screenPtr->RenderText(Vector2(2, 31), std::to_string(currentAbilitySelected + 1) + " / " + std::to_string(gameData->GetAbilities().size()));
			const Vector2 abilityNamePosition = Vector2(8, 31);
			const Vector2 abilityDescriptionPosition = Vector2(2, 32);
			const Vector2 abilityUsedAlrPosition = Vector2(2, 34);
			const int maxCharactersDescriptionPerLine = 30;
			//screenPtr->RenderText(Vector2(9, 30), std::to_string(currentAbilitySelected));

			EnemyData::ENEMYTYPE abilityType = gameData->GetAbilities()[currentAbilitySelected];

			//POISON
			if (abilityType == EnemyData::ENEMYTYPE::MUTANT) {
				screenPtr->RenderText(abilityNamePosition, "Ability: Poison");
				screenPtr->RenderTextWrap(abilityDescriptionPosition, "25% chance to apply poison to the enemy (The skill can be used repeatedly until poison is successfully applied.)", 70);

				if (abilities_poisonTurnsLeft > -1)
					screenPtr->RenderText(abilityUsedAlrPosition, "Ability has been used already!");
			}
			
			//HEALER
			else if (abilityType == EnemyData::ENEMYTYPE::HEALER) {
				screenPtr->RenderText(abilityNamePosition, "Ability: Recover");
				screenPtr->RenderText(abilityDescriptionPosition, "Heal self for 6HP (Use once per Battle)");

				if (abilities_hasUsedRestore)
					screenPtr->RenderText(abilityUsedAlrPosition, "Ability has been used already!");
			}

			//GUARD
			else if(abilityType == EnemyData::ENEMYTYPE::GUARD) {
				screenPtr->RenderText(abilityNamePosition, "Ability: Armour");
				screenPtr->RenderText(abilityDescriptionPosition, "Reduce damage taken by " + std::to_string(armourWeight));
				screenPtr->RenderText(Vector2(27, 32), "(Use once per Battle)");

				if (abilities_armourTurnsLeft > -1)
					screenPtr->RenderText(abilityUsedAlrPosition, "Ability has been used already!");
			}
		}
		
		else
		{
			screenPtr->RenderText(Vector2(2, 29), "Press 'ESC' to go back");
			screenPtr->RenderText(Vector2(2, 32), "No abilities unlocked yet!");
		}
			

		std::string LeftArrow = R"(   __     _    
  / /    / \   
 / /    / _ \  
 \ \   / ___ \ 
  \_\ /_/   \_\
      )";
		screenPtr->RenderDrawing(Vector2(79, 29), LeftArrow);

		std::string RightArrow = R"(  ____   __  
 |  _ \  \ \ 
 | | | |  \ \
 | |_| |  / /
 |____/  /_/ 
             
	)";
		screenPtr->RenderDrawing(Vector2(96, 29), RightArrow);

	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_ITEMS) 
	{
		if (gameData->GetInventory().size() > 0) {

			Item currentItem = gameData->GetInventoryItem(currentItemSelected);

			screenPtr->RenderText(Vector2(2, 29), "Press 'ESC' to go back");
			screenPtr->RenderText(Vector2(2, 31), std::to_string(currentItemSelected + 1) + " / " + std::to_string(gameData->GetInventorySize()));
			screenPtr->RenderText(Vector2(10, 31), currentItem.GetItemName());
			screenPtr->RenderTextWrap(Vector2(2, 32), currentItem.GetDescription(), 70);


			std::string LeftArrow = R"(   __     _    
  / /    / \   
 / /    / _ \  
 \ \   / ___ \ 
  \_\ /_/   \_\
      )";
			screenPtr->RenderDrawing(Vector2(79, 29), LeftArrow);

			std::string RightArrow = R"(  ____   __  
 |  _ \  \ \ 
 | | | |  \ \
 | |_| |  / /
 |____/  /_/ 
             
	)";
			screenPtr->RenderDrawing(Vector2(96, 29), RightArrow);

		}
		else
		{
			screenPtr->RenderText(Vector2(2, 29), "Press 'ESC' to go back");
			screenPtr->RenderText(Vector2(2, 32), "You have not collected any items yet!");
		}
		
	}

	else if (currentEvent == BATTLEEVENT::PLAYER_CHOICE_FLEE)
	{

	}

	else if (currentEvent == BATTLEEVENT::ENEMY_ATTACK)
	{

	}

	else if (currentEvent == BATTLEEVENT::PLAYER_DEATH) {

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

	if (poisonHitPlayer)
	{
		screenPtr->RenderText(Vector2(104, 25), "(Ps)");
	}

	screenPtr->RenderDrawing(playerFramePosition, currentPlayerFrame);

	//-----------------------------------------------------------------------------------------------


	if (currentBattleData->GetFirstEnemy()->IsAlive()) {


		screenPtr->RenderDrawing(Vector2(0, 0), currentBattleData->GetFirstEnemy()->currentFrame);

		screenPtr->RenderCharacter('+', 6, 24);
		screenPtr->RenderCharacter('+', 23, 24);

		// Enemy Health Stats bar (Single Battle)
		for (int i = 7; i < 23; i++)
			screenPtr->RenderCharacter('-', i, 24);
		for (int i = 25; i < 28; i++)
			screenPtr->RenderCharacter('|', 6, i);
		for (int i = 25; i < 28; i++)
			screenPtr->RenderCharacter('|', 23, i);

		for (int i = 25; i < 28; i++)
			for (int j = 7; j < 23; j++)
				screenPtr->RenderCharacter(' ', j, i);

		screenPtr->RenderText(Vector2(8, 25), currentBattleData->GetFirstEnemy()->GetEnemyName());
		screenPtr->RenderText(Vector2(8, 26), "Hp:  " + std::to_string(currentBattleData->GetFirstEnemy()->GetHealth()) + " / " + std::to_string(currentBattleData->GetFirstEnemy()->GetMaxHealth()));
		screenPtr->RenderText(Vector2(8, 27), "Atk: " + std::to_string(currentBattleData->GetFirstEnemy()->GetAttack()));
		//screenPtr->RenderTextWrap(Vector2(7, 23), currentBattleData->GetFirstEnemy()->GetEnemyDescription(), 17);

		if (abilities_poisonTurnsLeft > 0) {
			screenPtr->RenderText(Vector2(15, 25), "(Ps)");
		}

		if (isEnemyGuarding) {
			screenPtr->RenderText(Vector2(19, 25), "(Gd)");
		}

	}
	

	if (currentBattleData->IsDoubleBattle() && currentBattleData->GetSecondEnemy()->IsAlive())
	{
		screenPtr->RenderDrawing(Vector2(30, 0), currentBattleData->GetSecondEnemy()->currentFrame);

		screenPtr->RenderCharacter('+',37, 24);
		screenPtr->RenderCharacter('+', 54, 24);

		// Enemy Health Stats bar (Double Battle)
		for (int i = 38; i < 54; i++)
			screenPtr->RenderCharacter('-', i, 24);
		for (int i = 25; i < 28; i++)
			screenPtr->RenderCharacter('|', 37, i);
		for (int i = 25; i < 28; i++)
			screenPtr->RenderCharacter('|', 54, i);


		for (int i = 25; i < 28; i++)
			for (int j = 38; j < 54; j++)
				screenPtr->RenderCharacter(' ', j, i);

		screenPtr->RenderText(Vector2(39, 25), currentBattleData->GetSecondEnemy()->GetEnemyName());
		screenPtr->RenderText(Vector2(39, 26), "Hp:  " + std::to_string(currentBattleData->GetSecondEnemy()->GetHealth()) + " / " + std::to_string(currentBattleData->GetSecondEnemy()->GetMaxHealth()));
		screenPtr->RenderText(Vector2(39, 27), "Atk: " + std::to_string(currentBattleData->GetSecondEnemy()->GetAttack()));

		if (abilities_poisonTurnsLeft > 0) {
			if (currentBattleData->GetSecondEnemy()->IsAlive()) {
				screenPtr->RenderText(Vector2(46, 25), "(Ps)");
			}
		}
		if (isEnemyGuarding) {
			if (currentBattleData->GetSecondEnemy()->IsAlive()) {
				screenPtr->RenderText(Vector2(50, 25), "(Gd)");
			}
		}
	}

}


// Get which state the gamestate will be either it be the battle or world 
GAMESTATEVALUE GameStateBattle::GetGameStateValue()
{
	return GAMESTATEVALUE::BATTLESTATE;
}

/// <summary>
/// AHMAD
/// 
/// Apply the item effect on to the player 
/// </summary>
/// <param name="item"></param>
void GameStateBattle::ApplyItemUsage(Item item)
{
	if (item.GetItemType() == Item::ATTACK) {
		gameData->GetPlayerStats()->AddAttack(item.GetItemWeight());
	}
	else if (item.GetItemType() == Item::HEALING)
		gameData->GetPlayerStats()->HealPlayer(item.GetItemWeight());
	else if (item.GetItemType() == Item::DEFENCE)
		gameData->GetPlayerStats()->AddDefence(item.GetItemWeight());
}

/// <summary>
/// AHMAD
/// 
/// Removes the item effect on the player
/// </summary>
/// <param name="item"></param>
void GameStateBattle::RemoveItemUsage(Item item)
{
	if (item.GetItemType() == Item::ATTACK) {
		gameData->GetPlayerStats()->RemoveAttack(item.GetItemWeight());
	}
	else if (item.GetItemType() == Item::DEFENCE)
		gameData->GetPlayerStats()->RemoveDefence(item.GetItemWeight());
}

/// <summary>
/// KAYDEN
/// 
/// Update the item Usage left by -1 and when it reachs 0 remove the item
/// </summary>
void GameStateBattle::UpdateItemUsages()
{
	for (auto iterator = itemUsages.begin(); iterator != itemUsages.end();)
	{
		iterator->UpdateItemUsage();

		if (iterator->IsUsedUp()) {
			RemoveItemUsage(iterator->GetItem());
			iterator = itemUsages.erase(iterator);
		}
		else {
			++iterator;
		}
	}
}

/// <summary>
/// KAYDEN
/// 
/// updates the ability effect usage by -1 and when it reachs 0 remove the ability effect
/// </summary>
void GameStateBattle::UpdateAbilitiesUsage()
{
	if (abilities_armourTurnsLeft > 0) {
		abilities_armourTurnsLeft--;

		if (abilities_armourTurnsLeft <= 0) {
			gameData->GetPlayerStats()->RemoveDefence(armourWeight);
			abilities_armourTurnsLeft = 0;
		}
	}

	if (abilities_poisonTurnsLeft > 0) {
		abilities_poisonTurnsLeft--;

		if (abilities_poisonTurnsLeft <= 0) {
			abilities_poisonTurnsLeft = 0;
		}
	}
}

// Set the battle event to the current targetevent madde by the player
void GameStateBattle::SetBattleEvent(BATTLEEVENT targetEvent)
{
	currentEvent = targetEvent;
}

// Set the console text to whatever that haas been pass through
void GameStateBattle::SetConsoleText(std::string targetText)
{
	currentConsoleText = targetText;
}

// Clears the console with empty spaces
void GameStateBattle::ClearConsole()
{
	currentConsoleText = "";
}

// Get the set console text
std::string GameStateBattle::GetConsoleText()
{
	return currentConsoleText;
}


/// <summary>
/// KAYDEN
/// 
/// Play the player animation frame when being called and reseting back to idle animation
/// </summary>
/// <param name="frames"></param>
/// <param name="resetToIdle"></param>
void GameStateBattle::PlayAnimationSet(std::vector<std::string> frames, bool resetToIdle)
{
	for (int i = 0; i < frames.size(); i++) {
		currentPlayerFrame = frames[i];
		this->RenderScreen();
		Sleep(playerFrameInterval);
	}

	if (resetToIdle)
	{
		currentPlayerFrame = playerFrame_idle;
		this->RenderScreen();
		Sleep(playerFrameInterval);
	}
}

/// <summary>
/// KAYDEN
/// 
/// Play the enemy animation when being called and reseting back to idle animation
/// </summary>
/// <param name="targetEnemy"></param>
/// <param name="frameSet"></param>
/// <param name="resetToIdle"></param>
void GameStateBattle::PlayEnemyAnimationSet(EnemyData* targetEnemy, std::vector<std::string> frameSet, bool resetToIdle)
{
	for (int i = 0; i < frameSet.size(); i++) {
		targetEnemy->currentFrame = frameSet[i];
		this->RenderScreen();
		Sleep(playerFrameInterval);
	}

	if (resetToIdle)
	{
		targetEnemy->currentFrame = targetEnemy->idleFrame;
		this->RenderScreen();
		Sleep(playerFrameInterval);
	}
}
