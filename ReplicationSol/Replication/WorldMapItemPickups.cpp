#include "GameStateWorld.h"
#include "PickupInteractable.h"
#include "Vector2.h"
#include "Prop.h"

void GameStateWorld::SetLevelDataItemPickups() {


	{
		std::string metalBar = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			0, //Step 2. Define which Room the prop will be in
			Vector2(7, 13), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Metal bar obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Metal bar", 0, Item::ITEMTYPE::ATTACK, 3, 5,

				//   description
					"A rusty metal bar. Could be useful in a fight. Increases attack by 3 for 5 turns."), gameData),



			&metalBar, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}

	{
		std::string slop = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			2, //Step 2. Define which Room the prop will be in
			Vector2(53, 21), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Slop obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Slop", 0, Item::ITEMTYPE::HEALING, 2, 1,

					//   description
					"Unappetising food. Still edible, though. Heals 2 hp."), gameData),



			&slop, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}

	{
		std::string banana = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			2, //Step 2. Define which Room the prop will be in
			Vector2(34, 13), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Banana obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Banana", 0, Item::ITEMTYPE::HEALING, 6, 1,

					//   description
					"Nutritious. Ingest the potassium. Heals 6 hp."), gameData),



			&banana, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}

	{
		std::string soda = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			2, //Step 2. Define which Room the prop will be in
			Vector2(2, 15), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Hardening soda obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Hardening soda", 0, Item::ITEMTYPE::DEFENCE, 2, 3,

					//   description
					"Concrete flavoured soda that somehow hardens your body. Take 2 less damage for 3 turns."), gameData),



			&soda, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}

	{
		std::string pocketwatch = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			4, //Step 2. Define which Room the prop will be in
			Vector2(26, 14), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Pocket watch obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Pocket watch", 0, Item::ITEMTYPE::HEALING, 20, 1,

					//   description
					"Upon closer look, this unassuming pocket watch reverses the state of your body, bringing you back to being healthy. Heals you to maximum hp."), gameData),



			&pocketwatch, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}

	{
		std::string riotshield = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			5, //Step 2. Define which Room the prop will be in
			Vector2(45, 11), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Riot shield obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Riot shield", 0, Item::ITEMTYPE::DEFENCE, 4, 2,

					//   description
					"Shield. Might not be strong enough against your enemies. Take 4 less damage for 2 turns."), gameData),



			&riotshield, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}

	{
		std::string pistol = R"(|-|
|I|
|-|)";

		SpawnProp(new Prop(screenPtr,
			5, //Step 2. Define which Room the prop will be in
			Vector2(25, 16), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "Riot shield obtained" }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, //Num of lines AGAIN
				//   	 Name       Cost         Item type     weight turnusage
				Item("Pistol", 0, Item::ITEMTYPE::ATTACK, 4, 4,

					//   description
					"A sleek, silver pistol. Doesn't have much ammo left. Increases attack by 4 for 4 turns."), gameData),



			&pistol, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}
}