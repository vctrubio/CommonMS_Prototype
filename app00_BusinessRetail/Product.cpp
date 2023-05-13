#include "Product.hpp"

unsigned int Product::s_counterId = 1;

string	Product::getBsn()
{
	return _belongs_to->getName();
}

bool isNumeric(const std::string& str)
{
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

Product::~Product()
{
	if (!_transactions.empty())
	{
		string	filename = "CSV_LOG FOR BUSINESSES: " + _belongs_to->getName() + " |Product: " + _name;
		/*
		ostream file(filename);
		if (!file)
		{
			cout << RED << "Error in creating " << filename << ENDC << endl;
			return ;
		}
		//for (auto t : t
*/
	}

}
