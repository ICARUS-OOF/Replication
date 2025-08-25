#include "GameStateWorld.h"
#include "EnemyData.h"
#include "BattleData.h"
#include "Vector2.h"
#include "Prop.h"

void GameStateWorld::SetLevelDataBattles() {
	{
		//Use this to start at different rooms:
		//currentRoomIndex = 0;
		
		//Edit this to change player's starting position
		//                               position
		//worldPlayerPtr->MovePlayer(Vector2(0, 3));
	}

	//If finished, you can get rid of this template trigger
	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(15, 5, EnemyData::ENEMYTYPE::MUTANT),

			//SECOND ENEMY (put nullptr, for this entire line if single enemy)
			new EnemyData(15, 5, EnemyData::ENEMYTYPE::MUTANT),

			//Player FLEE POINT, CGOINS
			Vector2(0, 1), 2);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 0, Vector2(15, 5), Vector2(5, 5), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}




}