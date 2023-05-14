#include "Product.hpp"

unsigned int Product::s_counterId = 1;

string Product::getBsn()
{
	return _belongs_to->getName();
}

bool isNumeric(const std::string &str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
		{
			return false;
		}
	}
	return true;
}

Product::~Product()
{
	if (!_transactions.empty())
	{
		if (chdir("logsCSV") == -1)
		{
			
			cerr << "Error in chdir (CSV)\n";
				return;
		
		}

		string filename = "CSV_LOG FOR Business: " + _belongs_to->getName() + " => Product: " + _name;
		ofstream file(filename);
		if (!file)
		{
			cout << RED << "Error in creating (CSV) " << filename << ENDC << endl;
			return;
		}
		for (auto t : _transactions)
			file << t;
	}
}
