#include "Business.hpp"

Business::Business(User *user, string name):_belongs_to(user), _name(name), _revenue(0)
{
	_belongs_to->updateBsn(this);
}

void Business::test()
{
	cout << "Testing Name: " << _belongs_to->getName() << endl;
	cout << "BSN NAME: " << _belongs_to->getBsn() << endl;

}

bool isNumeric1(const std::string& str)
{
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void	Business::createProduct()
{
	string	input;
	string	name;
	int		price;

	cout << "To create a Product for: " << getName() << endl;
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
		if (input.length() > 0 && input.length() <= 9 && isNumeric1(input))
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

	Product	*prd = new Product(this, name, (unsigned int)price);
	_products.push_back(prd);
}

