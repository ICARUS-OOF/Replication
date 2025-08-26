#include "GameStateWorld.h"
#include "VendingMachineInteractable.h"

void GameStateWorld::SetLevelDataOthers() {
	std::string vendingMachineDrawing =
		R"(VENDING_MACHINE
)";


	{
		//----------VENDING FUCKING MACHINE-----------
		SpawnProp(new Prop(screenPtr,
			0, //Step 2. Define which Room the prop will be in
			Vector2(50, 5), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 1), //NO NEED WORRY ABOUT THIS
			Prop::PROPTYPE::MAP_LAYOUT, //If have collision, use: MAP_LAYOUT    No collision: MAP_LAYOUT_NONSOLID

			//If there is NO DIALOGUE, replace following 5 lines with nullptr,
			new VendingMachineInteractable(screenPtr, &currentInteractable, 1, gameData),

			& vendingMachineDrawing, //Step 7. Include the string variable name from step 1 here with the & in front
			nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			1, //Step 2. Define which Room the prop will be in
			Vector2(0, 25), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			2, //Step 2. Define which Room the prop will be in
			Vector2(0, 25), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			3, //Step 2. Define which Room the prop will be in
			Vector2(0, 25), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			3, //Step 2. Define which Room the prop will be in
			Vector2(0, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			7, //Step 2. Define which Room the prop will be in
			Vector2(0, 25), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			9, //Step 2. Define which Room the prop will be in
			Vector2(0, 25), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			9, //Step 2. Define which Room the prop will be in
			Vector2(80, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 25), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			10, //Step 2. Define which Room the prop will be in
			Vector2(80, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 25), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			10, //Step 2. Define which Room the prop will be in
			Vector2(-1, 0), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(1, 25), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	{
		//----------WALL-----------
		SpawnProp(new Prop(screenPtr,
			10, //Step 2. Define which Room the prop will be in
			Vector2(0, -1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr,nullptr,nullptr));
	}
	
}