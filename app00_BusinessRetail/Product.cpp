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

Product	*createProduct(Business *bsn)
{
	string	input;
	string	name;
	int		price;

	cout << "To create a Product for: " << bsn->getName() << endl;
	cout << "Tell us what you want to sell:\n>";
	while(true)
	{
		getline(cin, name);
		if (name.length() >= 3)
			break;
		cout << "For soimplicity, it must be more than 3 characters\n>";
	}

	cout << "Great, now at what price €/unit:\n>";
	while(true)
	{
		getline(cin, input);
		if (input.length() > 0 && input.length() <= 9 && isNumeric(input))
		{
			price = stoi(input);
			if (price > 0)
			{
				if (price >= 1000000)
				{
					cout << "Really!? More than a million bucks?\nSorry we dont sell bitcoins.\n";
					continue;
				}
				break;
			}
		}
		cout << "Price(INT) between 0 and A Million\n>";
	}

	Product	*prd = new Product(bsn, name, (unsigned int)price);
	bsn->addProduct(prd);
	return prd;
}

