#include "AI.h"

ai::ai()
{
	try
	{
		ifile.open("gameHistory.txt");
	}
	catch (fstream::failure& e)
	{
		cerr << "Error code:" << e.what() << endl;
	}

	dataVec = new vector<string>;
}

ai::~ai()
{
	ifile.close();
	delete dataVec;
}

/*Updates the vector of with new elements*/
void ai::updateVector()
{
	ifile.clear();
	while (getline(ifile, lineInput))
	{
		stat.updateStat(lineInput);
		dataVec->push_back(lineInput);
	}
}

/*Print the array*/
void ai::printHistory() const
{
	stat.printHistory();
	for (vector<string>::const_iterator it = dataVec->begin(); it != dataVec->end(); ++it)
	{
		cout << *it << endl;
	}
}