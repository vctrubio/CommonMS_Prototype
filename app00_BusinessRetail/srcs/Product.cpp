#include "../incl/Product.hpp"

unsigned int Product::s_counterId = 1;

string Product::getBsn()
{
	return _belongs_to->getName();
}

bool isNumeric(const string &str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

bool changeDirectoryOnce()
{
	static bool directoryChanged = false;
	filesystem::path currentPath = filesystem::current_path();
	string desiredDirectory = "logsCSV";

	if (currentPath != desiredDirectory && !directoryChanged)
	{
		filesystem::current_path(desiredDirectory);
		directoryChanged = true;
	}
	return directoryChanged;
}

Product::~Product()
{
	int total = 0;
	int count = 0;
	if (!_transactions.empty())
	{
		string filename = "CSV_LOG FOR Business: " + _belongs_to->getName() + " => Product: " + _name;
		ofstream file(filename);
		if (!file)
		{
			cout << RED << "Error in creating (CSV) " << filename << ENDC << endl;
			return;
		}
		for (auto t : _transactions)
		{
			file << t;
			count++;
		}
		total = _price * count;
		file << "\nTOTAL = " << total << "\nUnits = " << count << "\n";
	}
}
