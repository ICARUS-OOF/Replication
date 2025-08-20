#include "GameStateWorld.h"

#include "WorldEntity.h"
#include "WorldPlayer.h"
#include "Prop.h"
#include "GAMESTATEVALUE.h"

#include <iostream>
#include "GameData.h"


GameStateWorld::GameStateWorld(Screen* screenPtr, GAMESTATEVALUE* gameStateValuePtr, GameData* gameData)
{
	this->screenPtr = screenPtr;
	this->gameStateValuePtr = gameStateValuePtr;
	this->gameData = gameData;

	gameStateScreenSize = Vector2(80, 25);
	

	//Create player
	worldPlayerPtr = new WorldPlayer(screenPtr, Vector2(65, 14));

	// Initialize all props to Nullptr at first
	for (int i = 0; i < MAX_PROPS; i++)
		propArray[i] = nullptr;

	std::string akawkd =
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

	SpawnProp(new Prop(screenPtr, Vector2(0, 0), Vector2(1, 1), Prop::PROPTYPE::MAP_LAYOUT, nullptr, &akawkd));

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






void GameStateWorld::SpawnProp(Prop* propPtr)
{
	if (propSpawnIndex >= MAX_PROPS) {
		std::cout << "MAX PROPS REACHED! PLEASE INCREASE MAX_PROP ARRAY SIZE!!!" << std::endl;
		return;
	}

	propArray[propSpawnIndex] = propPtr;
	propSpawnIndex++;
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
				if (propArray[i] != nullptr) {
					//Loop thru all player body part positions
					for (int j = 0; j < worldPlayerPtr->PLAYER_POINTS_SIZE; j++)
					{
						//Check if each body part is overlapping with the wall
						if (propArray[i]->IsOverlapping(playerPoints[j])) {
							//If yes, then break and mark player has overlapped
							isPlayerOverlappingWithProp = true;
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

			*gameStateValuePtr = GAMESTATEVALUE::BATTLESTATE;
			gameData->SetCurrentBattleData(new BattleData(EnemyData(15, 4, EnemyData::ENEMYTYPE::MUTANT)));

			return;
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
		if (propArray[i] != nullptr)
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
