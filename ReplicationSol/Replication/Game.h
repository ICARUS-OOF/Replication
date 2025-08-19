#pragma once
#include <windows.h>
#include <iostream>
#include "WorldPlayer.h"
#include "Screen.h"
#include "Prop.h"
#include "Interactable.h";
#include "DialogueInteractable.h";

class Game
{
private:
	static const int pageRows = 25, pageCols = 80;

	WorldPlayer* worldPlayerPtr;
	Screen* screenPtr;

	static const int MAX_PROPS = 100;
	// An array of prop pointers
	Prop* propArray[MAX_PROPS];

	int propSpawnIndex = 0;

	Interactable* currentInteractable;

public:
	Game();
	void GameLoop();
	void DisplayWorld();
	void GetInputs();
	void RenderUI();

	void SpawnProp(Prop* propPtr);
};

