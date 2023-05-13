#include "Business.hpp"

Business::Business(User *user, string name):_belongs_to(user), _name(name), _revenue(0)
{
	_belongs_to->updateBsn(this);
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

void	Business::threading()
{
	int i = 0;
	while (true)
	{
		_queue.push_back(new Client("Maria" + to_string(i++)));
		cout << "Looped thread.\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (i >8)
			break;
	}
}

void	Business::createProduct()
{
	string	input;
	string	name;
	int		price;
	static int		s_int = 0;

	cout << "To create a Product for: " << getName() << endl;
	cout << "Tell us what you want to sell:\n>";
	while(true)
	{
		getline(cin, name);
		if (name.length() >= 3)
			break;
		if (s_int++ == 0)
			cout << "For simplicity, it must be more than 3 characters\n>";
	}

	cout << "Great, now at what price €/unit:\n>";
	while(true)
	{
		getline(cin, input);
		if (input.length() > 0 && input.length() <= 8 && isNumeric1(input))
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
		cout << "Price(INT) between A Euro and A Million\n>";
	}

	Product	*prd = new Product(this, name, (unsigned int)price);
	_products.push_back(prd);
}

void	Business::addInvoice(Client *client)
{
	cout << "Hello from addInvoice. on " << client->getName() << endl;

	Product	*product;
	while ((product = client->getProduct()) != NULL)
	{
		if (product->getPrice() > client->getPrice())
		{
			cout << "Not enough in " << RED << client->getName() << ENDC << " wallet.\n";
			cout << "Transaction not accepted... Removing _cart\n";
			client->products().clear();
			return ; 
		}
		_invoice = make_tuple(product, client, new Transaction(this, product, client));
		_revenue += product->getPrice();
		cout << "Transaction Succesfull.\n";
	}
}