#include "../Headers.hpp"
#include "User.hpp"
#include "Business.hpp"
#include "Product.hpp"


/* Check for valid name
 * +3 letters
 */

bool isNumeric(const std::string& str)
{
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

string	initBsn()
{
	string	input;

	cout << "Welcome to Common Solutions\n";
	cout << "To begin, please name your Business\n";
cout << "ie: Tom's Garage\n>";
	
	while(true)
	{
		getline(cin, input);
		if (input.length() >= 3)
			break;
		cout << "For soimplicity, it must be more than 3 characters\nAnd please, be careful(;\n>";
	}
	
	return input;
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

int main()
{
	User	*user = new User("Guest123");

	string	businessName;

	businessName = initBsn();
	cout << GREEN << "Creating Business: " << businessName << ENDC << endl;
	Business *bsn = new Business(user, businessName);
	
	cout << "Now let's start by listing your first product\n";

	Product *product;
	createProduct(bsn);


	cout << "Entering Loop, please know that you can press 0 anytime to quit\n";
	string input;
	while(true)
	{
		cout << "blablabla mssg: Index of products\n";
		cin >> input;
		if (input == "0")
			break;

	}


	delete user;
	delete bsn;

	return (1);
}
