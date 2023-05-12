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
