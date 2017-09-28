#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class statistics
{
public:
	statistics();
	~statistics();
	void printHistory() const;
	void updateVector();

protected:
	

private:
	string lineInput;
	vector<string> historyData;
	fstream ifile;
};