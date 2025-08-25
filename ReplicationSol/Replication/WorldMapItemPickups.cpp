#include "GameStateWorld.h"
#include "PickupInteractable.h"
#include "Vector2.h"
#include "Prop.h"

void GameStateWorld::SetLevelDataItemPickups() {
	std::string pickupDrawing = "PICKUP";


	{
		SpawnProp(new Prop(screenPtr,
			0, //Step 2. Define which Room the prop will be in
			Vector2(2, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT,  //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new PickUpInteractable(
				new std::string[1] //Step 4. Define the NUMBER OF LINES in []
				{ "You gained a.." }, //Step 5. Define the lines
				screenPtr, &currentInteractable,
				1, Item("Hardening Soda", 4, Item::ITEMTYPE::DEFENCE, 2, 3,
					"Concrete flavoured soda that somehow hardens your body. Take 2 less damage for 3 turns."), gameData), //Step 6. Define the NUMBER OF LINES AGAIN (Be sure that the number in step 4 is the same as in here)



			&pickupDrawing, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}


}