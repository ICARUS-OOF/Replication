#pragma once

#include "Screen.h"

class GameState
{
protected:
	Screen* screenPtr;

public:
	virtual void GetInputs() = 0;
	virtual void RenderObjects() = 0;
	virtual void RenderUI() = 0;
};

