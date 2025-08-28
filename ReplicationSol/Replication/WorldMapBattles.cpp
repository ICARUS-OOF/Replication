#include "GameStateWorld.h"
#include "EnemyData.h"
#include "BattleData.h"
#include "Vector2.h"
#include "Prop.h"

void GameStateWorld::SetLevelDataBattles() {
	{
		//Use this to start at different rooms:
		//currentRoomIndex = 8;
		
		//Edit this to change player's starting position
		//                               position
		//worldPlayerPtr->MovePlayer(Vector2(3, 10));
	}

	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(12, 6, EnemyData::ENEMYTYPE::MUTANT),

			//SECOND ENEMY (put nullptr, for this entire line if single enemy)
			nullptr,

			//Player FLEE POINT, CGOINS
			Vector2(76, 9), 5);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 1, Vector2(15, 6), Vector2(1, 20), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}
	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(11, 4, EnemyData::ENEMYTYPE::GUARD),

			//SECOND ENEMY (put nullptr, for this entire line if single enemy)
			nullptr,

			//Player FLEE POINT, CGOINS
			Vector2(76, 11), 5);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 3, Vector2(38, 1), Vector2(1, 24), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}
	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(11, 4, EnemyData::ENEMYTYPE::GUARD),

			//SECOND ENEMY (put nullptr, for this entire line if single enemy)
			new EnemyData(13, 2, EnemyData::ENEMYTYPE::HEALER),

			//Player FLEE POINT, CGOINS
			Vector2(39, 22), 10);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 5, Vector2(25, 19), Vector2(30, 1), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}
	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(12, 6, EnemyData::ENEMYTYPE::MUTANT),

			//SECOND ENEMY (put nullptr, for this entire line if single enemy)
			new EnemyData(13, 2, EnemyData::ENEMYTYPE::HEALER),

			//Player FLEE POINT, CGOINS
			Vector2(35, 2), 10);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 7, Vector2(58, 4), Vector2(1, 12), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}
	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(12, 6, EnemyData::ENEMYTYPE::MUTANT),

			//SECOND ENEMY (put nullptr, for this entire line if single enemy)
			new EnemyData(11, 4, EnemyData::ENEMYTYPE::GUARD),

			//Player FLEE POINT, CGOINS
			Vector2(3, 10), 10);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 8, Vector2(77, 6), Vector2(1, 13), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}






	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//    BOSS BATTLE                                                      
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(60, 2, EnemyData::ENEMYTYPE::BOSS),

			nullptr,

			//Player FLEE POINT, CGOINS
			Vector2(40, 13), 0);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 10, Vector2(0, 10), Vector2(100, 1), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}



}