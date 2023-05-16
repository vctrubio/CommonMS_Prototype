#include "../Headers.hpp"
#include "User.hpp"
#include "Business.hpp"
#include "Product.hpp"
#include "Transaction.hpp"
#include "Client.hpp"
#include "UI.hpp"
#include "Utils.hpp"

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
		cout << RED << "For simplicity" << ENDC << " it must be more than 3 characters\nAnd please, be carefull(;\n>";
	}
	return input;
}

void	initAQueue(Business *bsn)
{
	Client *miguel = new Client ("Miguel");
	miguel->addToCart(bsn->products().front());
	bsn->addQueue(miguel);
}

int main()
{
	clear();
	User	*user = new User("Guest123");
	string	businessName;

	mkdir("logsCSV", 0744);

	businessName = initBsn();
	cout << GREEN << "Creating Business: " << businessName << ENDC << endl;
	Business *bsn = new Business(user, businessName);

	cout << "................\nNow let's start by listing your first product\n";
	bsn->createProduct();

	initAQueue(bsn);

	uiBsn(bsn, 0);

	delete bsn;
	return (1);
}
