#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

#include "AI.h"

#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_UP 72
#define KB_DOWN 80

using namespace std;

class board
{
public:
	board();
	void printBoard() const;
	void printHistory() const; //debugging function
	void userController();
	void historyStream();
	void setMode(int mode);
	ai *AI;
	

protected:
	void gameOver();
	bool winCondition() const;
	bool isFull() const;
	void pushHistory();

	int turnCounter;
	bool secondFirst;
	int mode;
	char boardAr[9];
	int userPosition;
	char player;
	int KB_code;
	int history[11];
	int *historyPtr;
	fstream ofile;
};