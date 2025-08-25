#include "GameStateWorld.h"

#include "WorldEntity.h"
#include "WorldPlayer.h"
#include "Prop.h"
#include "VendingMachineInteractable.h"
#include "NoteInteractable.h"
#include "ButtonInteractable.h"
#include "GAMESTATEVALUE.h"
#include "BattleData.h"
#include "EnemyData.h"
#include "ExitInteractable.h"

#include <iostream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "GameData.h"


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
		//															roomIndex  position top-left  scale														//player emerging position
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 0, Vector2(5, 5), Vector2(4, 4), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(1); // Target room to go to
	}


	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(15, 5, EnemyData::ENEMYTYPE::MUTANT, "DESC", "SPRITE"),

			//SECOND ENEMY (put nullptr for this entire line if single enemy)
			new EnemyData(15, 5, EnemyData::ENEMYTYPE::MUTANT, "DESC", "SPRITE"), 
			
			//Player FLEE POINT, CGOINS
			 Vector2(0, 1),        2);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 0, Vector2(15, 5), Vector2(5, 5), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}
}


/// <summary>
/// KAYDEN
/// 
///OFFICIAL SETTING OF LEVEL PROP DATA
void GameStateWorld::SetLevelData()
{
	ExitInteractable* finalExit = new ExitInteractable(new std::string[2] //Step 4. Define the NUMBER OF LINES in []
		{ "It's locked", "Perhaps you need to go back and activate something..." }, //Step 5. Define the lines
		screenPtr, &currentInteractable,
		2, gameData);

	{
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string layout_room_0 =
				R"(XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                                                                               X
                                                                               X
                                                                               X
                                                                               X
                                                                               X
                                                                               X
                                                                               X
                                                                               X
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
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&layout_room_0, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}


		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string rubble =
				R"(|       /
|      |
|      |
|   __ |
 \ |  \|
  \|   \
   |    \
   |     \
)";

			SpawnProp(new Prop(screenPtr,
				0, //Step 2. Define which Room the prop will be in
				Vector2(67, 1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Looks like a cave-in.", "Hope nothing falls on me." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&rubble, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string brkdoor =
				R"( ________
|        |
 |        |	
  |        |
   |        |
    |________|
)";

			SpawnProp(new Prop(screenPtr,
				0, //Step 2. Define which Room the prop will be in
				Vector2(29, 2), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT_NONSOLID,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "A kicked down door.", "Whoever did this must be pretty strong..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&brkdoor, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string tubes =
				R"(      -------            -------            -------                             
   ///       \\\      ///       \\\      ///       \\\
  /             \    /             \    /             \
 /               \  /               \  /               \
 -               -  -               -  -               -
 \               /  \               /  \               /
  \             /    \             /    \             /
   \\\       ///      \\\       ///      \\\       ///
      -------            -------            -------

)";

			SpawnProp(new Prop(screenPtr,
				1, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Is that... me?" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&tubes, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string computer =
				R"(--------------------
|  ---------  ---- |
|             |  | |
|  XXXXXXXXX  |  | |
|  XXXXXXXXX  ---- |
--------------------
)";

			SpawnProp(new Prop(screenPtr,
				1, //Step 2. Define which Room the prop will be in
				Vector2(58, 1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Damn lockdown...", "Can't power this junk on." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&computer, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string papers =
				R"(------------------------------
|  ___   ----   -----        |
| /  /   |  |-  |   | -----  |
|/__/    ----|  ----- |   |  |
|         ----        -----  |
------------------------------
)";

			SpawnProp(new Prop(screenPtr,
				1, //Step 2. Define which Room the prop will be in
				Vector2(5, 13), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[4] //Step 4. Define the NUMBER OF LINES in []
					{ "So many research papers.", "Does that one have my name on it?", "The only readable words are...", "'Supersoldier', 'clone', and 'unforseen side effects'." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					4), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&papers, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string ttubes =
				R"(------------------------------
|   ------  ------  ------   |
|   O O OO  OO  OO  OOOO O   |
|   OOO  O  O O OO  O  O O   |
|   ------  ------  ------   |
------------------------------
)";

			SpawnProp(new Prop(screenPtr,
				1, //Step 2. Define which Room the prop will be in
				Vector2(45, 13), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Test tubes with different coloured liquids in them. Smells funny." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&ttubes, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string cells =
				R"(------------------------------          ------------------------------
|                            |          |                            |
)";

			SpawnProp(new Prop(screenPtr,
				1, //Step 2. Define which Room the prop will be in
				Vector2(5, 23), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "I am not going back in there." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&cells, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string trays =
				R"(|                                                                              |
|                                                                              |
|  MEAT     SEAFOOD     VEGGIES      FRUITS   SLOP      CARBS        DRINKS    |
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
|        ||   ||   ||             ||        ||   ||             ||             |
|        ||   ||   ||             ||        ||   ||             ||             |
---------------------------------------------     ------------------------------

)";

			SpawnProp(new Prop(screenPtr,
				2, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "At the very least they serve decent food.", "Not so decent now, though." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&trays, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string slop =
				R"(-----
)";

			SpawnProp(new Prop(screenPtr,
				2, //Step 2. Define which Room the prop will be in
				Vector2(45, 6), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[3] //Step 4. Define the NUMBER OF LINES in []
					{ "Eugh, gross.", "Although I gotta take what I can get...", "Slop obtained" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					3), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&slop, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string railing =
				R"(------------------------------------------------------------
------------------------------------------------------------
)";

			SpawnProp(new Prop(screenPtr,
				2, //Step 2. Define which Room the prop will be in
				Vector2(10, 9), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT_NONSOLID,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&railing, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string tables =
				R"(                      -------                       -------                     
                    ||       ||                   ||       ||                   
                   |           |                 |           |                  
                   |           |                 |           |                  
                   |           |                 |           |                  
      -------       ||       ||      -------      ||       ||     -------       
    ||       ||       -------      ||       ||      -------     ||       ||     
   |           |                  |           |                |           |    
   |           |                  |           |                |           |    
   |           |                  |           |                |           |    
    ||       ||                    ||       ||                  ||       ||     
      -------                        -------                      -------        
)";

			SpawnProp(new Prop(screenPtr,
				2, //Step 2. Define which Room the prop will be in
				Vector2(0, 12), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Food everywhere.", "Looks like they left in a hurry." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&tables, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string canteennote =
				R"([]
)";

			SpawnProp(new Prop(screenPtr,
				2, //Step 2. Define which Room the prop will be in
				Vector2(24, 20), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new NoteInteractable(screenPtr, &currentInteractable, R"(We just got a big contract from the government, and it's the biggest so far. I'm not sure what connections the senior execs have, but they managed to convince the government to pay a massive fortune for our latest supersoldier project.

They're desperate and losing it, I know they are. They just lost all the territory they had gained early in the war, and are just throwing money at whatever they think is going to be their saving grace. They're sending one of their best to be our lab rat, some guy named Pedro.

To be perfectly honest, I'm done with this company. It was only a couple days ago that they sent me the letter that my love was killed in an enemy assault. "She died for our country", they said. Screw that!

They started this war, and they're the ones who are gonna pay for the cost. They just accepted me into the project earlier, and it's going to be their last mistake.
)"),

&canteennote, //Step 7. Include the string variable name from step 1 here with the & in front
nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string  vendingmachine1 =
				R"(| |          | |
| |          | |
| |__________| |
|______________|
)";

			SpawnProp(new Prop(screenPtr,
				3, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&vendingmachine1, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string  loungeTV =
				R"(|______________________________|
)";

			SpawnProp(new Prop(screenPtr,
				3, //Step 2. Define which Room the prop will be in
				Vector2(24, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new NoteInteractable(screenPtr, &currentInteractable, R"(SITE STATUS: GAMMA LOCKDOWN

NON-COMBATIVE PERSONNEL ARE TO HEAD TO THE NEAREST EVACUATION BAY OR LOCKDOWN SHELTER

Security incident logs:
12:47: Massive riot in B-Wing, riot control dispatched.
13:00: Riot spreads to A-Wing, C-Wing, and D-Wing.
13:24: Control room is overrun, GAMMA-level lockdown initiated. External security teams dispatched.
14:02: Transformer fails, site-wide power outage occurs. Backup generators are activated.
15:01: External security teams arrive.
06:57: Fault in power line leading to heavy containment.
07:00: Subject 0 breaches containment.
)"),

&loungeTV, //Step 7. Include the string variable name from step 1 here with the & in front
nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string  loungetable =
				R"( ___     _____  
|   |   /     \ 
|___|   |     | 
        \_____/ 
                                                                                
          ___   
         |   |  
         |___|
)";

			SpawnProp(new Prop(screenPtr,
				3, //Step 2. Define which Room the prop will be in
				Vector2(65, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&loungetable, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string loungeplants =
				R"(    |                                                                    |       
  \ | /                                                                \ | /     
   \|/                                                                  \|/      
  |---|                                                                |---|     
  |   |                                                                |   |     
  |___|                                                                |___|
)";

			SpawnProp(new Prop(screenPtr,
				3, //Step 2. Define which Room the prop will be in
				Vector2(1, 19), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "I don't recall seeing these plants before..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&loungeplants, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string loungesofas =
				R"( ___                    ___  ___                    ___             
|   |__________________|   ||   |__________________|   |
|   |                  |   ||   |                  |   |
|   |                  |   ||   |                  |   |
|   |__________________|   ||   |__________________|   |
|                          ||                          |
|                          ||                          |
|__________________________||__________________________|
)";

			SpawnProp(new Prop(screenPtr,
				3, //Step 2. Define which Room the prop will be in
				Vector2(13, 18), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Looks comfy. I could take a quick nap on it, but it's not safe." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&loungesofas, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string officecubicletopleft =
				R"(||           |          ||
||     _____/           ||
||    |    ___          ||
||    |   |   |         ||
||    |   |___|         ||
||____|                 ||
||______________________||
|________________________|
)";

			SpawnProp(new Prop(screenPtr,
				4, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Noah Erik", "His stuff in in boxes, might be fired..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&officecubicletopleft, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string officecubiclemiddle =
				R"( ________________________                                                       
| ______________________ |                                                      
||           |          ||                                                      
||     _____/           ||                                                      
||    |    ___          ||                                                      
||    |   |   |         ||                                                      
||    |   |___|         ||                                                      
||____|                 ||                                                      
||______________________||
|________________________|
)";

			SpawnProp(new Prop(screenPtr,
				4, //Step 2. Define which Room the prop will be in
				Vector2(0, 8), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Thomas Chang", "Employee of the month" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&officecubiclemiddle, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string officecubiclebottomleft =
				R"( ________________________
| ______________________ |
||           |          ||
||     _____/           ||
||    |    ___          ||
||    |   |   |         ||
||    |   |___|         ||
)";

			SpawnProp(new Prop(screenPtr,
				4, //Step 2. Define which Room the prop will be in
				Vector2(0, 18), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "No name", "Looks like its vacant" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&officecubiclebottomleft, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string officecubiclebottomright =
				R"( ________________________ 
| ______________________ |
||          |           ||
||           \_____     ||
||          ___    |    ||
||         |   |   |    ||
||         |___|   |    ||
||                 |____||
||______________________||
)";

			SpawnProp(new Prop(screenPtr,
				4, //Step 2. Define which Room the prop will be in
				Vector2(54, 16), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Sarah Berkely", "Looks like she left in a hurry, her desk is quite messy" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&officecubiclebottomright, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string officecubicletopright =
				R"(||          |           ||
||           \_____     ||
||          ___    |    ||
||         |   |   |    ||
||         |___|   |    ||
||                 |____||
||______________________||
|________________________|
)";

			SpawnProp(new Prop(screenPtr,
				4, //Step 2. Define which Room the prop will be in
				Vector2(54, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Henry Adams", "Why does that name sound familiar?" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&officecubicletopright, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string officenote =
				R"([]
)";

			SpawnProp(new Prop(screenPtr,
				4, //Step 2. Define which Room the prop will be in
				Vector2(30, 21), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new NoteInteractable(screenPtr, &currentInteractable, R"(It's done. They're finished.

I sabotaged the cloning process, cranked up their production of stress hormones. I've even damaged the transformer so that they'll have an easier time breaking down doors.

Of course that means the whole site is in maximum lockdown now. The others are rushing to the escapes and shelters, but not me. Even if I wanted to, my route is blocked by the riots. Destroying the project was suicide, but by then I've already accepted it.

I can hear them getting closer. I'll die here, with the company, and the government.
)"),

&officenote, //Step 7. Include the string variable name from step 1 here with the & in front
nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string armorylockerleft =
				R"( ________________________________________________                
|        |               
|        |             
|        |             
|________|               
|      | |          
|      | |           
|      | |           
|      | |           
|______|_|         
|      | |           
|      | |           
|      | |          
|      | |         
|______|_|
)";

			SpawnProp(new Prop(screenPtr,
				5, //Step 2. Define which Room the prop will be in
				Vector2(15, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Riot control gear, and some heavy firearms..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&armorylockerleft, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string armorylockermiddle =
				R"(         |          |         |        |               
         |          |         |        |               
_________|__________|_________|        |               
_________|__________|_________|
)";

			SpawnProp(new Prop(screenPtr,
				5, //Step 2. Define which Room the prop will be in
				Vector2(25, 6), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Its quite empty", "Must've been them taking all the gear they could carry" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&armorylockermiddle, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string armorylockerright =
				R"(|________|               
| |      |               
| |      |               
| |      |               
| |      |               
|_|______|               
| |      |               
| |      |               
| |      |               
| |      |               
|_|______|
)";







			SpawnProp(new Prop(screenPtr,
				5, //Step 2. Define which Room the prop will be in
				Vector2(55, 9), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new ButtonInteractable(
					new std::string[4] //Step 4. Define the NUMBER OF LINES in []
					{ "Nothing in here", "Wait... What's that panel inside?", "You click something in the panel.", "Something seems to have opened." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					4, finalExit), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)

				&armorylockerright, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}




		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string armorynote =
				R"([]
)";

			SpawnProp(new Prop(screenPtr,
				5, //Step 2. Define which Room the prop will be in
				Vector2(30, 11), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new NoteInteractable(screenPtr, &currentInteractable, R"(What the hell is up with the prisoners?!

They're unusually coordinated and frenzied, they took out nearly half of the riot control units in less than 15 minutes!

I've locked myself in the armory with some of the others. The higher-ups keep yelling at us to get out and deal with the riots, but like hell I'm going out there ever again! I saw a whole crowd beat a single guard to a pulp!

I don't know how long it will be until they reach us. If I make it out of here alive I'm finding the lead scientist and putting a bullet in his cranium.

Those Frankensteins caused this. I'm sure of it.

)"),

&armorynote, //Step 7. Include the string variable name from step 1 here with the & in front
nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string armoryhallway =
				R"(                         ||                          ||                         
                         ||                          ||                         
                         ||                          ||                         
                         ||                          ||                         
                         ||                          ||                          
)";

			SpawnProp(new Prop(screenPtr,
				5, //Step 2. Define which Room the prop will be in
				Vector2(0, 20), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&armoryhallway, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string verticalhallway =
				R"(                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                        
                   |                                   |                                         
)";

			SpawnProp(new Prop(screenPtr,
				6, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,

				&verticalhallway, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string corner =
				R"(|                      
|                      
|                      
|______________________
)";

			SpawnProp(new Prop(screenPtr,
				7, //Step 2. Define which Room the prop will be in
				Vector2(57, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,


				&corner, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string shelves =
				R"(| ____________  |
||            | |
||            | |
||            | |
||            | |
||            | |
||____________| |
| _____________ |
||             ||
||             ||
||             ||
||             ||
||             ||
||_____________||
|_______________|
)";

			SpawnProp(new Prop(screenPtr,
				7, //Step 2. Define which Room the prop will be in
				Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Lots of supplies, meant for the office though. Shame." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&shelves, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string forklift =
				R"(  ____      ____ 
||____|____|____|
|     __________ |____________
|    |          ||
|    |          ||
|    |__________||____________
|________________|
||____|    |____|
)";

			SpawnProp(new Prop(screenPtr,
				7, //Step 2. Define which Room the prop will be in
				Vector2(1, 17), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "I'm not forklift certified..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&forklift, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string boxes =
				R"(           _____________________      
          |                     |     
 _________|                     |____ 
|         |                     |    |
|         |                     |    |
|         |                     |    |
|         |_____________________|    |
|                 |  |               |
|_________________|  |_______________|
)";

			SpawnProp(new Prop(screenPtr,
				7, //Step 2. Define which Room the prop will be in
				Vector2(40, 16), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Heavy weapons?", "Too bad I can't pry off the cover on these crates..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&boxes, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string warehousenote =
				R"([]
)";

			SpawnProp(new Prop(screenPtr,
				7, //Step 2. Define which Room the prop will be in
				Vector2(70, 8), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new NoteInteractable(screenPtr, &currentInteractable, R"(Transcript 016-08
CO: Status report on Prototype #09?

GA-1M: Successful. Escaped subjects are under its influence. Resistance levels are low and stable, over.

CO: Copy that GA-1M, proceed with caution.

GA-1M: Affirmative.
)"),

&warehousenote, //Step 7. Include the string variable name from step 1 here with the & in front
nullptr));
		}
		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string horizontalhallway =
				R"(--------------------------------------------------------------------------------
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
-------------------------------------------------------------------------------- 
)";

			SpawnProp(new Prop(screenPtr,
				8, //Step 2. Define which Room the prop will be in
				Vector2(0, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,


				&horizontalhallway, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string lobbyplant =
				R"(  \|/
   |
/\ | /\ 
  \|/ 
 |---|    
 |   |
 |___|
)";

			SpawnProp(new Prop(screenPtr,
				9, //Step 2. Define which Room the prop will be in
				Vector2(10, 1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "This one smells nice" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&lobbyplant, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string vendingmachine2 =
				R"( _______
|  _____
| |     
| |     
| |     
| |     
| |_____
|_______
)";

			SpawnProp(new Prop(screenPtr,
				9, //Step 2. Define which Room the prop will be in
				Vector2(72, 1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,


				&vendingmachine2, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string trashcan =
				R"(  __    
 /  \   
|    |  
 \__/ 
)";

			SpawnProp(new Prop(screenPtr,
				9, //Step 2. Define which Room the prop will be in
				Vector2(72, 17), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Nothing in here that helps me..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&trashcan, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string lifts =
				R"(           ____________________________  ____________________________           
          |             ||             ||             ||             |          
          |             ||             ||             ||             |          
          |             ||             ||             ||             |          
)";

			SpawnProp(new Prop(screenPtr,
				9, //Step 2. Define which Room the prop will be in
				Vector2(0, 22), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[2] //Step 4. Define the NUMBER OF LINES in []
					{ "Can't use the lifts because the power is out", "Doesn't matter anyways, it appears I'm on the top floor" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					2), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&lifts, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string lobbycarpet =
				R"(-                  -                              
|                  |
-                  - 
|                  |  
-                  -  
|                  |  
-                  -   
|                  |
-                  -
|__________________|
)";

			SpawnProp(new Prop(screenPtr,
				9, //Step 2. Define which Room the prop will be in
				Vector2(30, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT_NONSOLID,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,


				&lobbycarpet, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string foyercarpet =
				R"( __________________                               
|                  |                              
-                  -                  
|                  |                   
-                  -                  
|                  |                
-                  -            
|                  |                 
-                  -                
|                  |                
-                  -  
|                  |
-                  -                              
|                  |                              
-                  -                              
|                  |                              
-                  -                              
|                  |                              
-                  -                              
|                  |
)";

			SpawnProp(new Prop(screenPtr,
				10, //Step 2. Define which Room the prop will be in
				Vector2(30, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT_NONSOLID,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				nullptr,


				&foyercarpet, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string foyersofas =
				R"(___________                                                                     
           |                                                                    
     ______||
    |       |
    |       |
    |       |
    |       |
    |       |
    |______ |
           ||
___________|
___________ 
           |  
     ______||
    |       |
    |       |
    |       |
    |       |    
    |       |     
    |______ |    
           ||
___________| 
)";

			SpawnProp(new Prop(screenPtr,
				10, //Step 2. Define which Room the prop will be in
				Vector2(0, 3), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "I'm so tired, but the exit is right there..." }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&foyersofas, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
			//        And define the string in this format
			std::string receptionistdesk =
				R"(   ________
  /  ______
 /  /      
|  |    ___
|  |   |   
|  |   |   
|  |   |___
|  |       
 \  \______
  \________

)";

			SpawnProp(new Prop(screenPtr,
				10, //Step 2. Define which Room the prop will be in
				Vector2(69, 7), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
				Vector2(1, 1), //NO NEED WORRY ABOUT THIS
				Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

				//If there is NO DIALOGUE, replace following 5 lines with nullptr,
				new DialogueInteractable(
					new std::string[1] //Step 4. Define the NUMBER OF LINES in []
					{ "Papers everywhere, seems like whoever was here left in a jiffy" }, //Step 5. Define the lines
					screenPtr, &currentInteractable,
					1), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)


				&receptionistdesk, //Step 7. Include the string variable name from step 1 here with the & in front
				nullptr));
		}

		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left	scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 0, Vector2(0, 1), Vector2(1, 8), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(77, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(1); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 1, Vector2(79, 0), Vector2(1, 25), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(2, 5)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(0); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 1, Vector2(0, 0), Vector2(1, 25), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(77, 9)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(2); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 2, Vector2(79, 7), Vector2(1, 18), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(3, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(1); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 2, Vector2(1, 7), Vector2(1, 18), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(77, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(3); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 3, Vector2(79, 4), Vector2(1, 21), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(3, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(2); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 3, Vector2(1, 4), Vector2(1, 21), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(77, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(4); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 4, Vector2(79, 8), Vector2(1, 9), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(3, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(3); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 4, Vector2(26, 0), Vector2(28, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(42, 22)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(5); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 4, Vector2(26, 24), Vector2(28, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(39, 2)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(6); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 5, Vector2(27, 24), Vector2(26, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(39, 2)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(4); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 6, Vector2(20, 0), Vector2(35, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(39, 22)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(4); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 6, Vector2(20, 24), Vector2(35, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(37, 2)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(7); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 7, Vector2(17, 0), Vector2(40, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(37, 22)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(6); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 7, Vector2(79, 4), Vector2(1, 21), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(2, 11)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(8); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 8, Vector2(0, 6), Vector2(1, 13), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(77, 10)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(7); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 8, Vector2(79, 6), Vector2(1, 13), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(2, 12)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(9); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 9, Vector2(0, 0), Vector2(1, 25), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(77, 12)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(8); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 9, Vector2(31, 0), Vector2(18, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(40, 23)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(10); // Target room to go to
		}
		{
			//FOR LEVEL TRANSITIONS
			//															roomIndex  position top-left  scale														//player emerging position
			Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 10, Vector2(31, 24), Vector2(18, 1), Prop::PROPTYPE::LEVEL_TRANSITION_TRIGGER, nullptr, nullptr, new Vector2(40, 2)));
			levelTransitionTrigger->SetRoomTargetLevelTransitionTriggerIndex(9); // Target room to go to
		}





	}


	//--------EXIT---------
	{
		//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
		//        And define the string in this format
		std::string exit =
			R"(                    |                  ||                  |                    
                    |                  ||                  |                    
                    |__________________||__________________|                    


)";

		SpawnProp(new Prop(screenPtr,
			10, //Step 2. Define which Room the prop will be in
			Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			finalExit,


			& exit, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
		}


	{
		//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
		//        And define the string in this format
		std::string yourPropDesign =
			R"([[[[[]]]]]]
)";

		//----------VENDING FUCKING MACHINE-----------
		SpawnProp(new Prop(screenPtr,
			0, //Step 2. Define which Room the prop will be in
			Vector2(50, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new VendingMachineInteractable(screenPtr, &currentInteractable),

			& yourPropDesign, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}






	{
		//Step 1. Create the prop display as a string (for e.g std::string rubble (the name of your prop))
		//        And define the string in this format
		std::string yourPropDesign =
			R"([]
)";

		SpawnProp(new Prop(screenPtr,
			0, //Step 2. Define which Room the prop will be in
			Vector2(25, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new NoteInteractable(screenPtr, &currentInteractable, R"(It's been roughly 84 days since war broke out. Things have only gotten worse.

Since our oh-so-beloved government decided that it's best to channel everything - and I mean literally everything - into the war effort, they've sacked the economy and forced thousands into the uniform. Inflation and unemployment is at an all time high, families are starving on the streets, and it's all for the "greater good".

Can’t say I enjoy working for a soulless corporation that actively engages in war profiteering and gets big government contracts and funding often. As much as I hate them, it's the only job I have that gets me out of conscription and puts food on the table.

I just hope that this war ends before Christmas.)"),

&yourPropDesign, //Step 7. Include the string variable name from step 1 here with the & in front
nullptr));
	}


	{
		//------------------FOR BATTLE TRIGGERS-----------------
		//                                                          
		battleDataArray[battleSetIndex] = new BattleData(
			//         health atk                 EnemyType              
			new EnemyData(1, 5, EnemyData::ENEMYTYPE::MUTANT, "DESC", "SPRITE"),

			//SECOND ENEMY (put nullptr for this entire line if single enemy)
			new EnemyData(1, 5, EnemyData::ENEMYTYPE::MUTANT, "DESC", "SPRITE"),

			//Player FLEE POINT, CGOINS
			Vector2(0, 1), 2);
		//													      room | top-left position | scale
		Prop* levelTransitionTrigger = SpawnProp(new Prop(screenPtr, 0, Vector2(15, 5), Vector2(5, 5), Prop::PROPTYPE::BATTLE_TRIGGER, nullptr, nullptr, new Vector2(0, 0)));
		levelTransitionTrigger->SetBattleIndex(battleSetIndex);
		battleSetIndex++;
	}

}
