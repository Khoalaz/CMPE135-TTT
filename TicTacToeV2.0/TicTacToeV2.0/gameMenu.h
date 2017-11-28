#pragma once
#include "MenuAbstract.h"
#include "difficultyMenu.h"
#include "gameBoard.h"

class gameMenu : public menuAbstract
{
public:
	gameMenu();
	void userController();
private:
	difficultyMenu dMenu;
	gameBoard *game;
};