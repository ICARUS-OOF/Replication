#include "VendingMachineInteractable.h"
#include "Screen.h"
#include "Interactable.h"
#include "GameData.h"
#include "Item.h"
#include <iostream>


#include <conio.h>

VendingMachineInteractable::VendingMachineInteractable(Screen* screenPtr, Interactable** gameInteractablePtr, int vmIndex, GameData* gameDataptr)
{
	this->screenPtr = screenPtr;
	this->gameInteractablePtr = gameInteractablePtr;
	this->gameDataptr = gameDataptr;
	this->currentInteractionIndex = 0;
	this->isBuying = false;
	this->vmIndex = vmIndex;
}


void VendingMachineInteractable::Interaction()
{
	//currentInteractionIndex++;
	//if (currentInteractionIndex >= 3) {

	if (!isBuying)
		isBuying = true;

	if (isBuying) {
		char userInputvendingmachine = _getch();
		if (vmIndex == 1) {
			switch (userInputvendingmachine)
			{
				//ATTACK, HEALING, DEFENCE
				//Heal, don't need turnUSage
			case '1':
				if (gameDataptr->HasEnoughGcoins(2)) {
					std::cout << "You bought a banana!" << std::endl;
					gameDataptr->RemoveGcoins(2);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Banana", 2, Item::ITEMTYPE::HEALING, 6, 1, "Nutritious. Ingest the potassium. Heals 6 hp."));
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case '2':
				std::cout << "You bought a medkit!" << std::endl;
				if (gameDataptr->HasEnoughGcoins(4)) {
					std::cout << "You bought a medkit!" << std::endl;
					gameDataptr->RemoveGcoins(4);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Medkit", 4, Item::ITEMTYPE::HEALING, 10, 1, "A First Aid Kit. Only the bandage and antiseptic spray is left inside. Heals 10 hp."));
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case '3':
				if (gameDataptr->HasEnoughGcoins(4)) {
					std::cout << "You bought a riot shield!" << std::endl;
					gameDataptr->RemoveGcoins(4);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Riot shield", 4, Item::ITEMTYPE::DEFENCE, 4, 2, "Shield. Might not be strong enough against your enemies. Take 4 less damage for 2 turns."));
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case '4':
				if (gameDataptr->HasEnoughGcoins(2)) {
					std::cout << "You bought a hardening soda!" << std::endl;
					gameDataptr->RemoveGcoins(2);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Hardening soda", 2, Item::ITEMTYPE::DEFENCE, 2, 3, "Concrete flavoured soda that somehow hardens your body. Take 2 less damage for 3 turns."));
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case 27:
				isBuying = false;
				break;
			default:
				break;
			}
		}
		else if (vmIndex == 2) {
			switch (userInputvendingmachine)
			{
			case '1':
				if (gameDataptr->HasEnoughGcoins(8) && hasBoughtItem[0] == false) {
					std::cout << "You bought a portable barricade!" << std::endl;
					gameDataptr->RemoveGcoins(8);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Portable barricade", 8, Item::ITEMTYPE::DEFENCE, 8, 3, "A small device that materialises a barrier. It can't block all attacks though. Take 8 less damage for 3 turns"));
					hasBoughtItem[0] = true;
				}
				else if (hasBoughtItem[0] == true) {
					std::cout << "You already bought this item!" << std::endl;
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case '2':
				if (gameDataptr->HasEnoughGcoins(8) && hasBoughtItem[1] == false) {
					std::cout << "You bought a pocket watch!" << std::endl;
					gameDataptr->RemoveGcoins(8);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Pocket watch", 8, Item::ITEMTYPE::HEALING, 20, 1, "Upon closer look, this unassuming pocket watch reverses the state of your body, bringing you back to being healthy. Heals you to maximum hp."));
					hasBoughtItem[1] = true;
				}
				else if (hasBoughtItem[0] == true) {
					std::cout << "You already bought this item!" << std::endl;
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case '3':
				if (gameDataptr->HasEnoughGcoins(8) && hasBoughtItem[2] == false) {
					std::cout << "You bought an energy blaster!" << std::endl;
					gameDataptr->RemoveGcoins(8);
					//                       Name      Cost         Item type  weight turnusage description
					gameDataptr->AddItem(Item("Energy blaster", 8, Item::ITEMTYPE::ATTACK, 8, 3, "Powerful looking piece of technology. It's even rechargeable! Too bad you don't have a charging cable... Increases attack by 8 for 3 turns."));
					hasBoughtItem[2] = true;
				}
				else if (hasBoughtItem[0] == true) {
					std::cout << "You already bought this item!" << std::endl;
				}
				else {
					std::cout << "Insufficient funds!" << std::endl;
				}
				break;
			case 27:
				isBuying = false;
				break;
			default:
				break;
			}
		}
	}

	if (!isBuying) {
		currentInteractionIndex = 0;
		*gameInteractablePtr = nullptr;
	}
	//}
}

void VendingMachineInteractable::Render()
{
	const int top = 0;
	const int left = 0;
	const int right = 79;
	const int bottom = 25 - 1;

	screenPtr->RenderCharacter('+', left, top);

	for (int i = left + 1; i < right; i++)
		screenPtr->RenderCharacter('-', i, top);
	screenPtr->RenderCharacter('+', right, top);


	for (int i = top + 1; i < bottom; i++)
		screenPtr->RenderCharacter('|', right, i);
	screenPtr->RenderCharacter('+', right, bottom);


	for (int i = right - 1; i > left; i--)
		screenPtr->RenderCharacter('-', i, bottom);
	screenPtr->RenderCharacter('+', left, bottom);

	for (int i = bottom - 1; i > top; i--)
		screenPtr->RenderCharacter('|', left, i);

	const int dialogueStartTop = 2;
	const int dialogueStartLeft = 3;
	const int dialogueStartRight = 78;
	const int dialogueStartDown = 25;

	for (int i = dialogueStartTop; i < dialogueStartDown - 1; i++)
		for (int j = dialogueStartLeft - 1; j < dialogueStartRight; j++)
			screenPtr->RenderCharacter(' ', j, i);


	{
		////----RENDER CHARACTER---
		//screenPtr->RenderCharacter('X', Vector2(5, 10));

		////---SERIES OF CHARACTERS---
		//for (int i = 5; i < 11; i++)
		//{
		//	screenPtr->RenderCharacter('X', Vector2(i, 10));
		//}

		////----RENDERING DRAWING---
		//std::string myDrawing = R"(    ______________
  //|              |
  //|   [====]     |
  //|   [====]     |
  //|   [====]     |
  //|   [====]     |
  //|______________|)";
		//screenPtr->RenderDrawing(Vector2(40, 6), myDrawing);

		////------RENDER TEXT------
		//screenPtr->RenderText(Vector2(3, 3), "You found a vending machine!");
		//screenPtr->RenderTextWrap(Vector2(3, 6), "You found a vending machine!", 10);
	}

	if (vmIndex == 1)
	{
		std::string vendingmachine1frame = R"(          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X   /|     
          X                                                          X  / |     
          X                                                          X /  |     
          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX/   |)";
		screenPtr->RenderDrawing(Vector2(1, 0), vendingmachine1frame);
		screenPtr->RenderTextWrap(Vector2(2, 20), "   Ur   G-coins:    " + std::to_string(gameDataptr->GetGCoins()) + "    ", 8);

		std::string banana = R"(                &&  
               &&&&    
              &&  &   
            &&&  &&    
     _____&&&   &&___   
   /    &&&    &&   /   
  /  &&&&   &&&&   /  
 /    &&&&&&&     /    
/_______________ /   )";
		screenPtr->RenderDrawing(Vector2(18, 2), banana);
		screenPtr->RenderText(Vector2(21, 11), "1. Banana (2G)");

		std::string medkit = R"(    ________________     
   /_______________/|    
   |              | |   
   |     |--|     | | 
   |   ---  ---   | |
   |   |      |   |_|_ 
   |   ---  ---   | | /   
  /|     |--|     |/ /  
 / |______________| /   
/__________________/   )";
		screenPtr->RenderDrawing(Vector2(40, 1), medkit);
		screenPtr->RenderText(Vector2(43, 11), "2. Medkit (4G)");

		std::string riotshield = R"(     --------------    
     |            |
     |            |
     |------------|
     |    RIOT    |
    _|------------|____
   / |            |   /  
  /  |            |  / 
 /   -------------- /
/__________________/)";
		screenPtr->RenderDrawing(Vector2(17, 13), riotshield);
		screenPtr->RenderText(Vector2(18, 23), "3. Riot shield (4G)");

		std::string hardeningsoda = R"(     ----------     
    /          \   
    |__________|  
    |          |   
    |    []    |   
    |__________|____  
   /|          |   /  
  / \          /  / 
 /   ----------  /   
/_______________/)";
		screenPtr->RenderDrawing(Vector2(41, 13), hardeningsoda);
		screenPtr->RenderText(Vector2(40, 23), "4. Hardening Soda (2G)");
	}

	else if (vmIndex == 2)
	{
		std::string vendingmachine2frame = R"(          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X    |     
          X                                                          X   /|     
          X                                                          X  / |     
          X                                                          X /  |     
          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX/   |)";

		screenPtr->RenderDrawing(Vector2(1, 0), vendingmachine2frame);
		screenPtr->RenderTextWrap(Vector2(2, 20), "   Ur   G-coins:    " + std::to_string(gameDataptr->GetGCoins()) + "    ", 8);

		std::string portablebarrier = R"(    ____________   
   /===========/|__    
  /|  BARRIER  ||  /   
 / |___________|/ /  
/________________/)";

		if (!hasBoughtItem[0]) {
			screenPtr->RenderDrawing(Vector2(17, 6), portablebarrier);
			screenPtr->RenderText(Vector2(14, 11), "1. Portable barrier (8G)");
		}

		std::string pocketwatch = R"(        ___  
       |___|    
        | |  
      |||||||  
    ||   |   ||
   |     |__   | 
   |           |__ 
  / ||       ||  /
 /    |||||||   /   
/______________/)";

		if (!hasBoughtItem[1]) {
			screenPtr->RenderDrawing(Vector2(46, 1), pocketwatch);
			screenPtr->RenderText(Vector2(44, 11), "2. Pocket Watch (8G)");
		}

		std::string energyblaster = R"(                    __________________ 
                  _|                  |  
                 | |  ||  ||  || ||  ||_______________  
      ___________| ||||  ||  ||  ||||||              |   
   ___|             |________________| ==============O___ 
  ||         _____                   ||______________|  /
  ||        / \\ |__________________||                 /
 /||_______||                                         /
/____________________________________________________/)";

		if (!hasBoughtItem[2]) {
			screenPtr->RenderDrawing(Vector2(12, 14), energyblaster);
			screenPtr->RenderText(Vector2(27, 23), "3. Energy blaster (8G)");
		}
	}
}
