#include "Business.hpp"

Business::Business(User *user, string name):_belongs_to(user), _name(name), _revenue(0)
{
	_belongs_to->updateBsn(this);
}

Business::~Business()
{
	vector<Transaction*>	transaction;
	vector<Client*>			clients;

	for (auto product : _products)
		delete product;
	for (auto i : _invoice)
	{
		Client *client = get<1>(i);
		clients.push_back(client);
	}
	if (clients.size() > 0)
	{
		sort(clients.begin(), clients.end());
		auto uniq = std::unique(clients.begin(), clients.end());
		clients.erase(uniq, clients.end());
		for (auto client : clients)
			delete client;
	}
	delete _belongs_to;
}


bool isNumeric1(const std::string& str)
{
    for (char c : str)
	{
        if (!std::isdigit(c)) 
            return false;
    }
    return true;
}

Product	*Business::rtnRandomProduct()
{
	if (_products.empty())
		return nullptr; 
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dist(0, _products.size() - 1);
	size_t randomIndex = dist(gen);

	return _products[randomIndex];
}

void	Business::threading()
{
	int i = 0;
	while (true)
	{
		Client 	*ptr = new Client("Maria" + to_string(i++));
		Product	*prd = rtnRandomProduct();
		ptr->addToCart(prd);
		_queue.push_back(ptr);
		cout << GREEN << "!" << ENDC << ptr->getName() << " added to her cart: " << prd->getName() << endl;
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
	cout << GREEN << "Hello from addInvoice. on " << client->getName() << ENDC << endl;

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
		_invoice.push_back(make_tuple(product, client, new Transaction(this, product, client)));
		_revenue += product->getPrice();
		cout << GREEN << "+" << ENDC << client->getName() << " checked-out: " << product->getName() << endl;
	}
}
