#pragma once
#include "MenuAbstract.h"

class difficultyMenu: public menuAbstract
{
public:
	difficultyMenu();
	void userController();
private:
	int difficulty;
};