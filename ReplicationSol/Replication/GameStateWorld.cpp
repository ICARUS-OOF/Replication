#include "GameStateWorld.h"

#include "WorldEntity.h"
#include "WorldPlayer.h"
#include "Prop.h"
#include "VendingMachineInteractable.h"
#include "NoteInteractable.h"
#include "GAMESTATEVALUE.h"

#include <iostream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "GameData.h"
#include "MusicHandler.h"


GameStateWorld::GameStateWorld(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();

	gameStateScreenSize = Vector2(80, 25);

	this->currentRoomIndex = 0;
	//Create player
	worldPlayerPtr = new WorldPlayer(screenPtr, Vector2(35, 14));

	// Initialize all props to Nullptr at first
	for (int i = 0; i < MAX_PROPS; i++)
		propArray[i] = nullptr;
	for (int i = 0; i < MAX_BATTLES; i++)
		battleDataArray[i] = nullptr;






	SetLevelData();
	SetLevelDataBattles();
	SetLevelDataOthers();
	SetLevelDataItemPickups();
}

GameStateWorld::~GameStateWorld()
{
	for (int i = 0; i < MAX_PROPS; i++)
	{
		delete propArray[propSpawnIndex];
	}
}






Prop* GameStateWorld::SpawnProp(Prop* propPtr)
{
	if (propSpawnIndex >= MAX_PROPS) {
		std::cout << "MAX PROPS REACHED! PLEASE INCREASE MAX_PROP ARRAY SIZE!!!" << std::endl;
		_getch();
		return nullptr;
	}

	propArray[propSpawnIndex] = propPtr;
	propSpawnIndex++;

	return propPtr;
}

void GameStateWorld::OnStateEnter()
{
	if (gameData->GetCurrentBattleData() != nullptr) {
		if (gameData->GetCurrentBattleData()->GetBattleEndState() == BattleData::BATTLEEND::FLED) {
			worldPlayerPtr->MovePlayer(gameData->GetCurrentBattleData()->GetPlayerFleePoint());
		}
	}

	MusicHandler::PlayMusic("02_Prisoner");

	screenPtr->ResizeScreen(gameStateScreenSize);
	gameData->UpdateScreenAndViewportSizes(screenPtr->GetScreenSize(), screenPtr->GetConsoleViewportSize());
	this->ClearScreen();
	this->RenderScreen();
}

void GameStateWorld::Loop()
{
	if (currentInteractable == nullptr) {
		//Get the player's desired position based on input
		WorldPlayer::PLAYERDECISION playerDecision = worldPlayerPtr->GetPlayerInput();

		if (playerDecision == WorldPlayer::PLAYERDECISION::MOVE) {
			Vector2 desiredPlayerPos = worldPlayerPtr->targetPosition;

			//The boolean that checks if player overlapped with a prop
			bool isPlayerOverlappingWithProp = false;
			//An array of all player's body part positions
			Vector2* playerPoints = worldPlayerPtr->GetPlayerPoints(desiredPlayerPos);

			//Loop thru all props
			for (int i = 0; i < MAX_PROPS && !isPlayerOverlappingWithProp; i++)
			{
				if (propArray[i] != nullptr && propArray[i]->GetRoomIndex() == currentRoomIndex) {
					//Loop thru all player body part positions
					for (int j = 0; j < worldPlayerPtr->PLAYER_POINTS_SIZE; j++)
					{
						//Check if each body part is overlapping with the wall
						if (propArray[i]->IsOverlapping(playerPoints[j], true)) {

							Prop::PROPTYPE propType = propArray[i]->GetPropType();

							//If colliding with a level transition trigger
							if (propType == Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER) {
								//Load the target room
								currentRoomIndex = propArray[i]->GetRoomTargetLevelTransitionTriggerIndex();
								//Teleport player to the position
								worldPlayerPtr->MovePlayer(propArray[i]->GetRoomIndexOtherPointPosition());

								return;
							}
							else if (propType == Prop::PROPTYPE::BATTLE_TRIGGER) {

								if (battleDataArray[propArray[i]->GetBattleIndex()]->GetBattleEndState() != BattleData::BATTLEEND::WON) {
									gameData->SetGameStateValue(GAMESTATEVALUE::BATTLESTATE);
									gameData->SetCurrentBattleData(battleDataArray[propArray[i]->GetBattleIndex()]);

									return;
								}
							}
							else {
								isPlayerOverlappingWithProp = true;

								break;
							}
						}
					}
				}
			}

			//If no overlap, then player move
			if (!isPlayerOverlappingWithProp)
			{
				worldPlayerPtr->MovePlayer(desiredPlayerPos);
			}
		}
		else if (playerDecision == WorldPlayer::PLAYERDECISION::INTERACT) {



			Vector2* playerInteractivePoints = worldPlayerPtr->GetInteractivePoints(worldPlayerPtr->GetPosition());

			/*
			for (int j = 0; j < worldPlayerPtr->INTERACTIVE_POINTS_SIZE; j++) {
				std::cout << playerInteractivePoints[j].Getx() << "," << playerInteractivePoints[j].Gety() << ", ";
			}
			_getch();
			*/

			bool hasFoundInteractable = false;

			//Loop thru all props
			for (int i = 0; i < MAX_PROPS && !hasFoundInteractable; i++)
			{
				if (propArray[i] != nullptr && propArray[i]->GetRoomIndex() == currentRoomIndex) {
					if (propArray[i]->GetInteractable() != nullptr && propArray[i]->GetInteractable()->canInteract) {
						for (int j = 0; j < worldPlayerPtr->INTERACTIVE_POINTS_SIZE; j++)
						{
							if (propArray[i]->IsOverlapping(playerInteractivePoints[j], false)) {

								currentInteractable = propArray[i]->GetInteractable();
								hasFoundInteractable = true;
								break;
							}
						}
					}
				}
			}
		}
		else if (playerDecision == WorldPlayer::PLAYERDECISION::RUN_TESTBATTLE) {
			DEBUG_BATTLETEST();
		}
		else if (playerDecision == WorldPlayer::PLAYERDECISION::SWAP_PUZZLEROOMS) {
			if (currentRoomIndex == 5)
				currentRoomIndex = 10;
			else
				currentRoomIndex = 5;
		}
	}
	else {
		if (currentInteractable != nullptr) {
			currentInteractable->Interaction();
		}
	}

	this->RenderScreen();
}

void GameStateWorld::RenderBaseObjects()
{
	for (int i = 0; i < MAX_PROPS; i++)
	{
		if (propArray[i] != nullptr && propArray[i]->GetRoomIndex() == currentRoomIndex)
			propArray[i]->RenderCharacterDisplay();
	}

	worldPlayerPtr->RenderCharacterDisplay();
}

void GameStateWorld::RenderBaseUI()
{
	if (currentInteractable != nullptr) {
		currentInteractable->Render();
	}
}

GAMESTATEVALUE GameStateWorld::GetGameStateValue()
{
	return GAMESTATEVALUE::WORLDSTATE;
}

void GameStateWorld::DEBUG_BATTLETEST()
{
	gameData->SetGameStateValue(GAMESTATEVALUE::BATTLESTATE);
	std::string enemySprite_Mutant = R"(             |HHHHHHHH|
     |HHHH####H∙∙∙∙∙##H|
    |HH#∙∙∙∙∙∙∙∙∙ ∙∙∙∙∙##|
   |HH∙∙∙ ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙##|
 |##∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙##|
|## ∙∙∙∙∙∙∙∙∙∙ ∙∙∙∙∙∙∙∙∙##|
|# ∙∙∙∙∙∙∙∙∙∙ ∙∙∙|H####∙∙##|
|#∙∙∙∙∙∙∙∙∙ H ∙ ∙#######∙##|
|#∙∙∙∙∙∙∙∙#HH∙∙∙∙##   #####|
|#####∙∙HH#HH∙∙∙∙##   #####|
|###∙#######|∙∙∙∙|## ######|
 |##∙ #####|∙∙∙∙∙#######∙##|
 |H#∙∙∙∙∙∙∙∙∙∙#∙##∙∙∙∙∙####|
 |H#∙##∙| ∙∙ ##∙##|∙∙∙##H#|
  |H#∙## ∙∙∙∙∙∙∙∙∙∙∙ ####|
   |#####∙∙∙∙∙∙∙∙∙ ####∙#|
    ###################∙#|
    |##∙###############∙#|
     |#∙###############∙#|
      |#∙#############∙##|
      |##∙∙|#######∙∙∙##|
       |##∙∙∙∙∙∙∙∙∙∙##|
        |###########H|)";

	std::string enemySprite_Healer = R"(                      HHHH                  
        ###          H#####H                
 ##HHH   ###         H#####H                
#+--++#   ##          H###H                 
#-----+#####          I+++I                 
 #++--++++##    ##HHHHH+++HHHHHHH####       
   #+++#       ###+++++++++++++++++++##     
   #++++#     #+++I++++++++++++##+++++##    
   ##++++#####+++#I++++###+++++I ##+++##    
     #++++++++++##I++#HHHHH#++#I  #++++##   
       ##HHHHH##  I++#HHHHH#++I   I##+--++I 
                  I+++####H+++I I#++-------I
                  I#++++++++++II+--++II++--I
                   I+I++++++#I I++-+I  I+--I
                     I+++++I    I#++#I I++#I
                     I+++++I                
                     I#+++#I                
                     I#HHH#I                
                    I#######I               
                    I#######I               
                     ######H 

)";

	gameData->SetCurrentBattleData(new BattleData(
		//           Hp atk            enemy type: GUARD MUTANT HEALER
		new EnemyData(20, 4, EnemyData::ENEMYTYPE::GUARD),


		//new EnemyData(6, 4, EnemyData::ENEMYTYPE::MUTANT, "", enemySprite_Mutant),

		Vector2(16, 9), 
		
		100));
}
