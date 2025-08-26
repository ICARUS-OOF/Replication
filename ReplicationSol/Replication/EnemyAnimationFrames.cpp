#include "EnemyData.h"

void EnemyData::SetAnimations() {
	/*
	std::string idleFrame;
	std::vector<std::string> enemyFrames_attack, enemyFrames_damaged, enemyFrames_ability, enemyFrames_death;
	*/

	if (enemyType == ENEMYTYPE::MUTANT) {
		idleFrame = R"(MUTANT IDLEEEE)";


	}





	else if (enemyType == ENEMYTYPE::HEALER) {
		idleFrame = R"(HEALER IDLEEEE)";
	}






	else if (enemyType == ENEMYTYPE::GUARD) {
		idleFrame = R"(GUARD IDLEEEE)";
	}

	


	else if (enemyType == ENEMYTYPE::BOSS) {
		idleFrame = R"(BOSS IDLEEE)";
	}




	currentFrame = idleFrame;
}