#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>

#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define KB_UP 72
#define KB_DOWN 80

using namespace std;

//HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class gameBoard
{
public:
	gameBoard();
	void printBoard() const;
	void userController();

protected:
	HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void gameOver();
	bool isFull() const;
	bool winCondition()const;
	void pushHistory();
	void historyStream();


	bool botFlag;

	int *historyPtr;
	int history[11] = {};
	int turnCounter;
	int userPosition;
	char player;
	int KB_code;
	char boardAr[9];
	fstream ofile;
};