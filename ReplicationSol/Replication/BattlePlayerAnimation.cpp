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
    //2. playerFrames_fight - The frames when player attacks enemy
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
-----------------------------------
|                         ##      |
|      ####################       |
|    ########################     |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|###...#........##.........#...###|
|    ###...................###    |
|      #...................#      |
|      ###......###......###      |
|       ####.#.......#.####       |
|           ###########           |
-----------------------------------)";
     currentPlayerFrame = playerFrame_idle;



     {
         //FLEE ANIMATION
         playerFrames_flee.push_back(
             R"(
-----------------------------------
|                         ##      |
|         ####################    |
|    ##########################   |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########..######..#..##########|
|#....##..####....#..####..##....#|
|#.....###.....#..##.....###.....#|
|#.....###..#...#.....#..###.....#|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");

         playerFrames_flee.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH     HHHHHHHHHH   HHHHHH HH HHH|
|HHHH HHHHHHHHHHH HHHH HHH HH HH H|
|HHHH HHHHHHHHHHH      HHH HH HH H|
|HH     HHHHHHHHH HHHH HHH HHHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
| #############################   |
| #############################   |
|##########..######..#..##########|
|#....##..####....#..####..##....#|
|#.....###.....#..##.....###.....#|
|#.....###..#...#.....#..###.....#|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");

         playerFrames_flee.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH     HHHHHHHHHH   HHHHHH HH HHH|
|HHHH HHHHHHHHHHH HHHH HHH HH HH H|
|HHHH HHHHHHHHHHH      HHH HH HH H|
|HH     HHHHHHHHH HHHH HHH HHHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH   HHH HHH H     H     HH    HH|
|H HHH HH HHH HHH HHHHH HHH HHHH H|
|H HHH HH HHH HHH HHHHH HHH      H|
|H HHH HH HHH HHH HHHHH HHH HHHH H|
|HH   HHHH   HHHH H#HHH HHH HHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");


         playerFrames_flee.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH     HHHHHHHHHH   HHHHHH HH HHH|
|HHHH HHHHHHHHHHH HHHH HHH HH HH H|
|HHHH HHHHHHHHHHH      HHH HH HH H|
|HH     HHHHHHHHH HHHH HHH HHHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH   HHH HHH H     H     HH    HH|
|H HHH HH HHH HHH HHHHH HHH HHHH H|
|H HHH HH HHH HHH HHHHH HHH      H|
|H HHH HH HHH HHH HHHHH HHH HHHH H|
|HH   HHHH   HHHH H#HHH HHH HHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|H HHHHH HH     H        HH      #|
|H HHHHH HH HHHHH  HHHH  HH HHHHHH|
|H       HH     H       HHH H    H|
|H HHHHH HH HHHHH  HHH  HHH HHHHHH|
|H HHHHH HH     H HHHHH  HH      H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_flee.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH     HHHHHHHHHH   HHHHHH HH HHH|
|HHHH HHHHHHHHHHH HHHH HHH HH HH H|
|HHHH HHHHHHHHHHH      HHH HH HH H|
|HH     HHHHHHHHH HHHH HHH HHHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HH   HHH HHH H     H     HH    HH|
|H HHH HH HHH HHH HHHHH HHH HHHH H|
|H HHH HH HHH HHH HHHHH HHH      H|
|H HHH HH HHH HHH HHHHH HHH HHHH H|
|HH   HHHH   HHHH H#HHH HHH HHHH H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|H HHHHH HH     H        HH      #|
|H HHHHH HH HHHHH  HHHH  HH HHHHHH|
|H       HH     H       HHH H    H|
|H HHHHH HH HHHHH  HHH  HHH HHHHHH|
|H HHHHH HH     H HHHHH  HH      H|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");


     }




     {
         //SPECIAL ATTACK ANIMATION
         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|    ########################     |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|###...#........##.........#...###|
|    ###...................###    |
|      #...................#      |
|      ###......###......###      |
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|###...#........##.........#...###|
|    ###...................###    |
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|##########....####.....##########|
|#....##..######..#######..##....#|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");


         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHH HHHHHHHHHHHHHHHHHHHHHHHHH HHH|
|HH HHHHHHHHHHHHHHHHHHHHHHHHHHH HH|
|H HHHHHHHHHHHHHHHHHHHHHHHHHHHHH H|
| HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH |
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
| HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH |
|H HHHHHHHHHHHHHHHHHHHHHHHHHHHHH H|
|HH HHHHHHHHHHHHHHHHHHHHHHHHHHH HH|
|HHH HHHHHHHHHHHHHHHHHHHHHHHHH HHH|
-----------------------------------)");


         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHH HHHHHHHHHHHHHHH HHHHHHHH|
|HHHHHHH HHHHHHHHHHHHHHHHH HHHHHHH|
|HHHHHH HHHHHHHHHHHHHHHHHHH HHHHHH|
|HHHHH HHHHHHHHHHHHHHHHHHHHH HHHHH|
|HHHH HHHHHHHHHHHHHHHHHHHHHHH HHHH|
|HHH HHHHHHHHHHHHHHHHHHHHHHHHH HHH|
|HH HHHHHHHHHHHHHHHHHHHHHHHHHHH HH|
|H HHHHHHHHHHHHHHHHHHHHHHHHHHHHH H|
| HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH |
| HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH |
|H HHHHHHHHHHHHHHHHHHHHHHHHHHHHH H|
|HH HHHHHHHHHHHHHHHHHHHHHHHHHHH HH|
|HHH HHHHHHHHHHHHHHHHHHHHHHHHH HHH|
|HHHH HHHHHHHHHHHHHHHHHHHHHHH HHHH|
|HHHHH HHHHHHHHHHHHHHHHHHHHH HHHHH|
|HHHHHH HHHHHHHHHHHHHHHHHHH HHHHHH|
|HHHHHHH HHHHHHHHHHHHHHHHH HHHHHHH|
|HHHHHHHH HHHHHHHHHHHHHHH HHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHH HHH HHHHHHHHHHHHHH|
|HHHHHHHHHHHHH HHHHH HHHHHHHHHHHHH|
|HHHHHHHHHHHH HHHHHHH HHHHHHHHHHHH|
|HHHHHHHHHHH HHHHHHHHH HHHHHHHHHHH|
|HHHHHHHHHH HHHHHHHHHHH HHHHHHHHHH|
|HHHHHHHHH HHHHHHHHHHHHH HHHHHHHHH|
|HHHHHHHH HHHHHHHHHHHHHHH HHHHHHHH|
|HHHHHHH HHHHHHHHHHHHHHHHH HHHHHHH|
|HHHHHH HHHHHHHHHHHHHHHHHHH HHHHHH|
|HHHHHH HHHHHHHHHHHHHHHHHHH HHHHHH|
|HHHHHHH HHHHHHHHHHHHHHHHH HHHHHHH|
|HHHHHHHH HHHHHHHHHHHHHHH HHHHHHHH|
|HHHHHHHHH HHHHHHHHHHHHH HHHHHHHHH|
|HHHHHHHHHH HHHHHHHHHHH HHHHHHHHHH|
|HHHHHHHHHHH HHHHHHHHH HHHHHHHHHHH|
|HHHHHHHHHHHH HHHHHHH HHHHHHHHHHHH|
|HHHHHHHHHHHHH HHHHH HHHHHHHHHHHHH|
|HHHHHHHHHHHHHH HHH HHHHHHHHHHHHHH|
-----------------------------------)");


         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHH HHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHH H HHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHH HHH HHHHHHHHHHHHHH|
|HHHHHHHHHHHHH HHHHH HHHHHHHHHHHHH|
|HHHHHHHHHHHH HHHHHHH HHHHHHHHHHHH|
|HHHHHHHHHHH HHHHHHHHH HHHHHHHHHHH|
|HHHHHHHHHH HHHHHHHHHHH HHHHHHHHHH|
|HHHHHHHHHH HHHHHHHHHHH HHHHHHHHHH|
|HHHHHHHHHHH HHHHHHHHH HHHHHHHHHHH|
|HHHHHHHHHHHH HHHHHHH HHHHHHHHHHHH|
|HHHHHHHHHHHHH HHHHH HHHHHHHHHHHHH|
|HHHHHHHHHHHHHH HHH HHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHH H HHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHH HHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHH HHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHH H HHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHH HHH HHHHHHHHHHHHHH|
|HHHHHHHHHHHHH HHHHH HHHHHHHHHHHHH|
|HHHHHHHHHHHHH HHHHH HHHHHHHHHHHHH|
|HHHHHHHHHHHHHH HHH HHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHH H HHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHH HHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHH       HHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHH           HHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
|HHHHHHHHH               HHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
|HHHHH                       HHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
|HH                             HH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");


         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
-----------------------------------)");

         playerFrames_abilities.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");




     }






     {
		 //DAMAGED ANIMATION
         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|                         ##      |
|         ####################    |
|    ##########################   |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########..######..#..##########|
|#....##..####....#..####..##....#|
|#.....###.....#..##.....###.....#|
|#.....###..#...#.....#..###.....#|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");

         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHH  HHHHHH|
|HHHHHHHHH                    HHHH|
|HHHH                          HHH|
|HHHH                         HHHH|
|HHH                           HHH|
|HHH                           HHH|
|H                             HHH|
|H                             HHH|
|          HH      HH HH          |
| HHHH  HH    HHHH HH    HH  HHHH |
| HHHHH   HHHHH HH  HHHHH   HHHHH |
| HHHHH   HH HHH HHHHH HH   HHHHH |
|   HHH  HHHHHHH  HHHHHHHH  HHH   |
|HHHH   HHHHHHHHHHHHHHHHHHH   HHHH|
|HHHHHH HHHHHHH  HHHHHHHHHH HHHHHH|
|HHHHHH   HHH   HH  HHHHH   HHHHHH|
|HHHHHHH     H  HH HH H    HHHHHHH|
|HHHHHHHHHHHH         HHHHHHHHHHHH|
-----------------------------------  )");


         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|                         ##      |
|         ####################    |
|    ##########################   |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########..######..#..##########|
|#....##..####....#..####..##....#|
|#.....###.....#..##.....###.....#|
|#.....###..#...#.....#..###.....#|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");


         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHH  HHHHHH|
|HHHHHHHHH                    HHHH|
|HHHH                          HHH|
|HHHH                         HHHH|
|HHH                           HHH|
|HHH                           HHH|
|H                             HHH|
|H                             HHH|
|          HH      HH HH          |
| HHHH  HH    HHHH HH    HH  HHHH |
| HHHHH   HHHHH HH  HHHHH   HHHHH |
| HHHHH   HH HHH HHHHH HH   HHHHH |
|   HHH  HHHHHHH  HHHHHHHH  HHH   |
|HHHH   HHHHHHHHHHHHHHHHHHH   HHHH|
|HHHHHH HHHHHHH  HHHHHHHHHH HHHHHH|
|HHHHHH   HHH   HH  HHHHH   HHHHHH|
|HHHHHHH     H  HH HH H    HHHHHHH|
|HHHHHHHHHHHH         HHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|                         ##      |
|         ####################    |
|    ##########################   |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########..######..#..##########|
|#....##..####....#..####..##....#|
|#.....###.....#..##.....###.....#|
|#.....###..#...#.....#..###.....#|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");

         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHH  HHHHHH|
|HHHHHHHHH                    HHHH|
|HHHH                          HHH|
|HHHH                         HHHH|
|HHH                           HHH|
|HHH                           HHH|
|H                             HHH|
|H                             HHH|
|          HH      HH HH          |
| HHHH  HH    HHHH HH    HH  HHHH |
| HHHHH   HHHHH HH  HHHHH   HHHHH |
| HHHHH   HH HHH HHHHH HH   HHHHH |
|   HHH  HHHHHHH  HHHHHHHH  HHH   |
|HHHH   HHHHHHHHHHHHHHHHHHH   HHHH|
|HHHHHH HHHHHHH  HHHHHHHHHH HHHHHH|
|HHHHHH   HHH   HH  HHHHH   HHHHHH|
|HHHHHHH     H  HH HH H    HHHHHHH|
|HHHHHHHHHHHH         HHHHHHHHHHHH|
-----------------------------------)");

         playerFrames_damaged.push_back(
             R"(
-----------------------------------
|                         ##      |
|         ####################    |
|    ##########################   |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########..######..#..##########|
|#....##..####....#..####..##....#|
|#.....###.....#..##.....###.....#|
|#.....###..#...#.....#..###.....#|
|###...##.......##........##...###|
|    ###...................###    |
|      #.......##..........#      |
|      ###...###..##.....###      |
|       #####.##..#..#.####       |
|            #########            |
-----------------------------------)");



     }





     {
		 //FIGHT ANIMATION
         playerFrames_fight.push_back(
             R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|    ########################     |
|    #########################    |
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|###...#........##.........#...###|
|    ###...................###    |
|      #...................#      |
|      ###......###......###      |
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");
     }

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|   ###########################   |
|   ###########################   |
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|###...#........##.........#...###|
|    ###...................###    |
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
| #############################   |
| #############################   |
|##########....####.....##########|
|#....##..######..#######..##....#|
|#.....#.....#....#..#.....#.....#|
|#.....#.....#..#....#.....#.....#|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|##########....####.....##########|
|#....##..######..#######..##....#|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHH   H  HHHHHHHHHHHHHH|
|HHHHHHHHHH H HHHHHHHHH HHHHHHHHHH|
|HHHHHHHHHH HHHHHHHHHH H HHHHHHHHH|
|HHHHHHHHHH HH HH HHHH H HHHHHHHHH|
|HHHHHHHHHHH H H  H  H H HHHHHHHHH|
|HHHHHHHHHHHHHHHH  HHHH HHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHH       HHHHHHHHHHHH|
|HHHHHHHHHH    HH HHHH HHHHHHHHHHH|
|HHHHHHH H HHHHHHHHHHHH HHHHHHHHHH|
|HHHHHHH HHHHHHHHH  HH H  HHHHHHHH|
|HHHHHHH HH HHH HH  HH H  HHHHHHHH|
|HHHHHHH HH HHH HH  HH H  HHHHHHHH|
|HHHHHHHH H   H  H   H H  HHHHHHHH|
|HHHHHHHHHHHHHHH  HHHHH HHHHHHHHHH|
|HHHHHHHHHHHHHHHH      HHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");



     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHH          HHHHHHHHHHH|
|HHHHHHHHH     HHH  HHHHH  HHHHHHH|
|HHHHHH   HHH  HHHHHHHHHHHH HHHHHH|
|HHHH  HHHHHHHHHHHHHHHHHHH  HHHHHH|
|HHHH  HHHHHHHHHHHHH  HHH  H  HHHH|
|HHHH  HHH HHHH  HHH  HHH  H  HHHH|
|HHHH  HHH  HHH  HHH  HHH  H  HHHH|
|HHHH  HHH  HHH  HHH  HHH  H  HHHH|
|HHHHHH HH   HH   HH   HH  H  HHHH|
|HHHHHHH                 HH HHHHHH|
|HHHHHHHHHHHHHHHH HHHHHHHHH HHHHHH|
|HHHHHHHHHHHHHHHHH        HHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------))");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHH             HHHHHHH|
|HHHHHHH       HHH     H  H  HHHHH|
|HHHHHHH      HHHHH  HHHHHH  HHHHH|
|HHH    HHHH  HHHHHHHHHHHHHHH  HHH|
|H  HH  HHHHHHHHHHHHHHHHHHHHH  HHH|
|H  HHHHHHHHHHHHHHHHH  HHHH  HH  H|
|H  HHHHHHHHHH   HHHH  HHHH  HH  H|
|H  HHHH  HHHH   HHHH  HHHH  HH  H|
|H  HHHH  HHHH   HHHH  HHHH  HH  H|
|H  HHHH  HHHH   HHHH  HHHH  HH  H|
|HHH HHH    HH    HHH    HH  HH  H|
|HHH  HH    HH     HH    HH  HH  H|
|HHHHH                     HH  HHH|
|HHHHHHHHHHHHHHH   HHHHHHHHHH  HHH|
|HHHHHHHHHHHHHHHHHH          HHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|                                 |
|             #############       |
|       #######   ##### ## ##     |
|       ######     ##      ##     |
|   ####    ##               ##   |
| ##  ##                     ##   |
| ##                 ##    ##  ## |
| ##          ###    ##    ##  ## |
| ##    ##    ###    ##    ##  ## |
| ##    ##    ###    ##    ##  ## |
| ##    ##    ###    ##    ##  ## |
|   #   ####  ####   ####  ##  ## |
|   ##  ####  #####  ####  ##  ## |
|     #####################  ##   |
|               ###          ##   |
|                  ##########     |
|                                 |
|                                 |
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHH             HHHHHHH|
|HHHHHHH       HHH     H  H  HHHHH|
|HHHHHHH      HHHHH  HHHHHH  HHHHH|
|HHH    HHHH  HHHHHHHHHHHHHHH  HHH|
|H  HH  HHHHHHHHHHHHHHHHHHHHH  HHH|
|H  HHHHHHHHHHHHHHHHH  HHHH  HH  H|
|H  HHHHHHHHHH   HHHH  HHHH  HH  H|
|H  HHHH  HHHH   HHHH  HHHH  HH  H|
|H  HHHH  HHHH   HHHH  HHHH  HH  H|
|H  HHHH  HHHH   HHHH  HHHH  HH  H|
|HHH HHH    HH    HHH    HH  HH  H|
|HHH  HH    HH     HH    HH  HH  H|
|HHHHH                     HH  HHH|
|HHHHHHHHHHHHHHH   HHHHHHHHHH  HHH|
|HHHHHHHHHHHHHHHHHH          HHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|                                 |
|             #############       |
|       #######   ##### ## ##     |
|       ######     ##      ##     |
|   ####    ##               ##   |
| ##  ##                     ##   |
| ##                 ##    ##  ## |
| ##          ###    ##    ##  ## |
| ##    ##    ###    ##    ##  ## |
| ##    ##    ###    ##    ##  ## |
| ##    ##    ###    ##    ##  ## |
|   #   ####  ####   ####  ##  ## |
|   ##  ####  #####  ####  ##  ## |
|     #####################  ##   |
|               ###          ##   |
|                  ##########     |
|                                 |
|                                 |
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHH                   HHHHHH|
|HHHHHH                       HHHH|
|HHHH                          HHH|
|HHH                            HH|
|HHH                            HH|
|HHHH                          HHH|
|HHHHHH                      HHHHH|
|HHHHHHHHH                HHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHH                           HHH|
|HHH                           HHH|
|H                               H|
|H                               H|
|H                               H|
|H                               H|
|HHH                           HHH|
|HHH                           HHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHH                           HHH|
|HHH                           HHH|
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|HH                            HHH|
|HH                            HHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
|HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH|
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
-----------------------------------)");

     playerFrames_fight.push_back(
         R"(
-----------------------------------
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
-----------------------------------)");



}








     //INSERT CODE HERE


