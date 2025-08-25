#pragma once
class Interactable
{
public:
	virtual void Interaction() = 0;
	virtual void Render() = 0;
	bool canInteract = true;
};

