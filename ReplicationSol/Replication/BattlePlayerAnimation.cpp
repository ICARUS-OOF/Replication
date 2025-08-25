#include "GameStateBattle.h"

void DOCUMENTATION_SetBattleAnimations() {
    std::vector <std::string> playerFrames_damaged;

    //---------For Junshen---------
    //To add each frame to each animation, copy all code within these brackets into the bottom of SetBattleAnimations()
    {
        //The frame set you want to damage
        playerFrames_damaged.push_back(
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
            #########  )");
    }

    //You can select one of the following animation sets and replace "playerFrames_damaged" with it
    //1. playerFrames_damaged - The frames when player is damaged
    //2. playerFrames_attack - The frames when player attacks enemy
    //3. playerFrames_abilities - When using an ability
    //4. playerFrames_flee - When fleeing
    //5. playerFrames_death - When dying
    //6. playerFrames_poisoned - When player is poisoned

    //To trigger a battle, press "F" to trigger the test battle
    

    //To Change the settings of a battle,
    //1. Go to GameStateWorld.cpp
    //2. Go to DEBUG_TESTBATTLE() at around line 265
    //3. Change the settings according to the comments

    //Do note that each frame has a 300ms wait time (I think lol)
}

void GameStateBattle::SetBattleAnimations() {
     playerFrame_idle =
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
     currentPlayerFrame = playerFrame_idle;








     //INSERT CODE HERE

}
