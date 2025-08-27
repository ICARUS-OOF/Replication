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


/// <summary>
/// KAYDEN
/// 
/// CONSTRUCTOR
/// Concrete state inheriting from GameState
/// This class is to handle all logic for the world
/// </summary>
/// <param name="gameData"></param>
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





	//Call all functions to lay out levels
	SetLevelData();
	SetLevelDataBattles();
	SetLevelDataOthers();
	SetLevelDataItemPickups();
}

//Destructor, simply destroys all battles
GameStateWorld::~GameStateWorld()
{
	for (int i = 0; i < MAX_PROPS; i++)
		delete propArray[propSpawnIndex];
	for (int i = 0; i < MAX_BATTLES; i++)
		delete battleDataArray[i];
}





/// <summary>
/// KAYDEN
/// 
/// Registers a prop to the game for rendering an interaction
/// </summary>
/// <param name="propPtr"></param>
/// <returns></returns>
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

/// <summary>
/// KAYDEN
/// 
/// When entering this new game state
/// </summary>
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

/// <summary>
/// KAYDEN
/// 
/// MAIN CALLING LOOP FOR THE WORLD
/// </summary>
void GameStateWorld::Loop()
{
	//If there isnt an interactable that player interacts with right now
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

							//Triggering a battle
							else if (propType == Prop::PROPTYPE::BATTLE_TRIGGER) {

								//If battle has not been won yet, then trigger the battle
								if (battleDataArray[propArray[i]->GetBattleIndex()]->GetBattleEndState() != BattleData::BATTLEEND::WON) {
									gameData->SetGameStateValue(GAMESTATEVALUE::BATTLESTATE);
									gameData->SetCurrentBattleData(battleDataArray[propArray[i]->GetBattleIndex()]);

									return;
								}
							}
							else {
								//If the player is overlapping with a prop that is not any of the above triggers, interact with the prop
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
		//-----IF INTERACTION KEY IS PRESSED
		else if (playerDecision == WorldPlayer::PLAYERDECISION::INTERACT) {


			//-------
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
							//More specific interaction
							if (propArray[i]->IsOverlapping(playerInteractivePoints[j], false)) {

								currentInteractable = propArray[i]->GetInteractable();
								//Mark as has found interactable to break
								hasFoundInteractable = true;
								break;
							}
						}
					}
				}
			}
		}





		//----------DEBUGGING PURPOSES---------
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
		//If player is currently interacting with something, play the interaction
		if (currentInteractable != nullptr) {
			currentInteractable->Interaction();
		}
	}

	this->RenderScreen();
}

void GameStateWorld::RenderBaseObjects()
{
	//Prop rendering if room corresponds
	for (int i = 0; i < MAX_PROPS; i++)
		if (propArray[i] != nullptr && propArray[i]->GetRoomIndex() == currentRoomIndex)
			propArray[i]->RenderCharacterDisplay();

	worldPlayerPtr->RenderCharacterDisplay();
}

void GameStateWorld::RenderBaseUI()
{
	if (currentInteractable != nullptr) {
		//Just renders the interactable's drawing
		currentInteractable->Render();
	}
}

/// <summary>
/// Return GameState in enum value form
/// </summary>
/// <returns></returns>
GAMESTATEVALUE GameStateWorld::GetGameStateValue()
{
	return GAMESTATEVALUE::WORLDSTATE;
}



//-------- DEBUGGING ONLY -------
void GameStateWorld::DEBUG_BATTLETEST()
{
	gameData->SetGameStateValue(GAMESTATEVALUE::BATTLESTATE);
	std::string enemySprite_Mutant = R"(             
			|HHHHHHHH|
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
		//new EnemyData(20, 4, EnemyData::ENEMYTYPE::GUARD),
		new EnemyData(10, 4, EnemyData::ENEMYTYPE::HEALER),

		Vector2(16, 9), 
		
		100));
}
