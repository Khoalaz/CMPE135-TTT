#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <conio.h>

#define KB_UP 72
#define KB_DOWN 80

using namespace std;

class menuAbstract {
public:
	/*Prints out the menu with selection highlights*/
	const void printMenu()
	{
		system("cls");
		int counter = 0;
		for (vector<string>::iterator it = menu.begin(); it != menu.end(); it++)
		{
			cout << counter+1 << ". ";
			if (ptrPos == counter)
			{
				SetConsoleTextAttribute(mConsole, 128);
				cout << *it;
				SetConsoleTextAttribute(mConsole, 7);
			}
			else
			{
				cout << *it;
			}
			cout << endl;
			counter++;
		}
	};
	/*virtual function for user controlls*/
	virtual void userController(){};

protected:
	HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int KB_code = 0;
	vector<string> menu;
	int ptrPos = 0;
};