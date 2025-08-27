#include "GameStateWorld.h"
#include "VendingMachineInteractable.h"

void GameStateWorld::SetLevelDataOthers() {
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
			Vector2(0, -1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
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
	



	{
		//----------ITEM PICKUP-----------
		SpawnProp(new Prop(screenPtr,
			10, //Step 2. Define which Room the prop will be in
			Vector2(0, -1), //Step 3. Define Position(X, Y) OF THE TOP-LEFT OF PROP
			Vector2(80, 1), //SCALE
			Prop::PROPTYPE::WALL, nullptr, nullptr, nullptr));
	}
}