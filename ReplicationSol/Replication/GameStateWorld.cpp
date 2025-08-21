#include "GameStateWorld.h"

#include "WorldEntity.h"
#include "WorldPlayer.h"
#include "Prop.h"
#include "GAMESTATEVALUE.h"

#include <iostream>
#include <chrono>
#include <thread>
#include "GameData.h"


GameStateWorld::GameStateWorld(GameData* gameData)
{
	this->gameData = gameData;
	this->screenPtr = gameData->GetScreenPtr();

	gameStateScreenSize = Vector2(80, 25);
	

	//Create player
	worldPlayerPtr = new WorldPlayer(screenPtr, Vector2(65, 14));

	// Initialize all props to Nullptr at first
	for (int i = 0; i < MAX_PROPS; i++)
		propArray[i] = nullptr;






	SetLevelData();








	/*
	{
		// Creating prop Wall in index of prop array
		SpawnProp(new Prop(screenPtr, Vector2(0, 0), Vector2(80, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(79, 0), Vector2(1, 10), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(69, 9), Vector2(11, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(69, 9), Vector2(1, 4), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(69, 12), Vector2(6, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(74, 12), Vector2(1, 6), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(55, 17), Vector2(20, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(55, 12), Vector2(1, 6), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(55, 12), Vector2(6, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(60, 9), Vector2(1, 4), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(44, 9), Vector2(17, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(44, 9), Vector2(1, 4), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(44, 12), Vector2(6, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(49, 12), Vector2(1, 6), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(30, 17), Vector2(20, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(30, 12), Vector2(1, 6), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(30, 12), Vector2(6, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(35, 9), Vector2(1, 4), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(19, 9), Vector2(17, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(19, 9), Vector2(1, 4), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(19, 12), Vector2(6, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(24, 12), Vector2(1, 6), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(5, 17), Vector2(20, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(5, 12), Vector2(1, 6), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(5, 12), Vector2(6, 1), Prop::PROPTYPE::RIGHT_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(10, 9), Vector2(1, 4), Prop::PROPTYPE::DOWN_WALL));
		SpawnProp(new Prop(screenPtr, Vector2(0, 9), Vector2(11, 1), Prop::PROPTYPE::RIGHT_WALL));



		SpawnProp(new Prop(screenPtr, Vector2(55, 5), Vector2(6, 3), Prop::PROPTYPE::WALL, new DialogueInteractable(
			new std::string[3]
			{
				"Looks like a cave-in", "Hope nothing falls on me.", "akajaijawjakjn dahdka"
			},
			screenPtr, &currentInteractable,
			3)));
	}
	*/
}

/// <summary>
/// KAYDEN
/// 
/// TUTORIAL ON HOW TO CREATE A LEVEL PROPS
/// </summary>
void GameStateWorld::DOCUMENTATION_DONOTCALL()
{
	//-----------------PROP WITH DIALOGUE OR NO DIALOGUE-------------
	//Copy and Paste all of this in the brackets INCLUDING BRACKETS (So u can collapse and organise)
	{
		//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
		//        And define the string in this format
		std::string yourPropDesign =
			R"(|       /
|      |
|      |
|   __ |
|  \|
|   \
|    \
|     \
)";

		SpawnProp(new Prop(screenPtr,
		0, //Step 2. Define which Room the prop will be in
		Vector2(34, 15), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
		Vector2(1, 1), //NO NEED WORRY ABOUT THIS
		Prop::PROPTYPE::MAP_LAYOUT_NONSOLID, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

		//If there is NO DIALOGUE, replace following 5 lines with nullptr,
		new DialogueInteractable(
			new std::string[3] //Step 4. Define the NUMBER OF LINES in []
			{ "This is lne 1!", "This is line 2!", "This is line 3!" }, //Step 5. Define the lines
			screenPtr, &currentInteractable,
			3), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

		&yourPropDesign, //Step 7. Include the string variable name from step 1 here with the & in front
		nullptr));
	}

	{
		//FOR LEVEL TRANSITIONS
		//																position top-left	scale																//player emerging position
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 0, Vector2(5, 5), Vector2(4, 4), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(1); // Target room to go to
	}


}


/// <summary>
/// KAYDEN
/// 
///OFFICIAL SETTING OF LEVEL PROP DATA
void GameStateWorld::SetLevelData()
{
	{
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string layout_room_0 =
				R"(XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                                                                   |       /   X
                              _________                            |      |    X
                             |        |                            |      |    X
                              |        |                           |   __ |    X
                               |        |                           \ |  \|    X
                                |        |                           \|   \    X
                                 |________|                           |    \   X
                                                                      |     \  X
XXXXXXXXXXX        XXXXXXXXXXXXXXXXX        XXXXXXXXXXXXXXXXX        XXXXXXXXXXX
          X        X               X        X               X        X          
          X        X               X        X               X        X          
     XXXXXX        XXXXXX     XXXXXX        XXXXXX     XXXXXX        XXXXXX     
     X                  X     X                  X     X                  X     
     X                  X     X                  X     X                  X     
     X                  X     X                  X     X                  X     
     X                  X     X                  X     X                  X     
     XXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXX     
)";

			SpawnProp(new Prop(screenPtr,
				0, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT_NONSOLID, //OR THIS

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&layout_room_0, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
	}
}






Prop* GameStateWorld::SpawnProp(Prop* propPtr)
{
	if (propSpawnIndex >= MAX_PROPS) {
		std::cout << "MAX PROPS REACHED! PLEASE INCREASE MAX_PROP ARRAY SIZE!!!" << std::endl;
		return nullptr;
	}

	propArray[propSpawnIndex] = propPtr;
	propSpawnIndex++;

	return propPtr;
}

void GameStateWorld::OnStateEnter()
{
	screenPtr->ResizeScreen(gameStateScreenSize);
}

void GameStateWorld::GetInputs()
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
						if (propArray[i]->IsOverlapping(playerPoints[j])) {
							//If yes, then break and mark player has overlapped
							isPlayerOverlappingWithProp = true;

							//If colliding with a level transition trigger
							if (propArray[i]->GetPropType() == Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER) {
								//Load the target room
								currentRoomIndex = propArray[i]->GetRoomTargetLevelTransitionTriggerIndex();
								//Teleport player to the position
								worldPlayerPtr->MovePlayer(propArray[i]->GetRoomIndexOtherPointPosition());
								return;
							}

							break;
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

			/*
			{
				if (currentRoomIndex == 0)
					currentRoomIndex = 1;
				else
					currentRoomIndex = 0;

				return;
			}*/
			/*
			{
				gameData->SetGameStateValue(GAMESTATEVALUE::BATTLESTATE);
				gameData->SetCurrentBattleData(new BattleData(EnemyData(15, 4, EnemyData::ENEMYTYPE::MUTANT)));

				return;
			}
			*/

			Vector2* playerInteractivePoints = worldPlayerPtr->GetInteractivePoints(worldPlayerPtr->GetPosition());
			bool hasFoundInteractable = false;

			//Loop thru all props
			for (int i = 0; i < MAX_PROPS && !hasFoundInteractable; i++)
			{
				if (propArray[i] != nullptr) {
					if (propArray[i]->GetInteractable() != nullptr) {
						for (int j = 0; j < worldPlayerPtr->INTERACTIVE_POINTS_SIZE; j++)
						{
							if (propArray[i]->IsOverlapping(playerInteractivePoints[j])) {

								currentInteractable = propArray[i]->GetInteractable();
								hasFoundInteractable = true;
								break;
							}
						}
					}
				}
			}
		}
	}
	else {
		if (currentInteractable != nullptr) {
			currentInteractable->Interaction();
		}
	}
}

void GameStateWorld::RenderObjects()
{
	for (int i = 0; i < MAX_PROPS; i++)
	{
		if (propArray[i] != nullptr && propArray[i]->GetRoomIndex() == currentRoomIndex)
			propArray[i]->RenderCharacterDisplay();
	}

	worldPlayerPtr->RenderCharacterDisplay();
}

void GameStateWorld::RenderUI()
{
	if (currentInteractable != nullptr) {
		currentInteractable->Render();
	}
}

GAMESTATEVALUE GameStateWorld::GetGameStateValue()
{
	return GAMESTATEVALUE::WORLDSTATE;
}
