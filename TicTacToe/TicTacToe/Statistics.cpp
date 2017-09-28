#include"Statistics.h"

statistics::statistics()
{
	try
	{
		ifile.open("gameHistory.txt");
	}
	catch (fstream::failure& e)
	{
		cerr << "Error code:" << e.what() << endl;
	}
}

statistics::~statistics()
{
	ifile.close();
	historyData.~vector();
}

/*Prints every elements in a vector*/
void statistics::printHistory() const
{
	for (vector<string>::const_iterator it = historyData.begin(); it != historyData.end(); ++it)
	{
		cout << *it << endl;
	}
}

/*Updates the vector of with new elements*/
void statistics::updateVector()
{
	ifile.clear();
	while (getline(ifile, lineInput))
	{
		historyData.push_back(lineInput);
	}
}