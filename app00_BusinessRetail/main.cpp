#include "../Headers.hpp"
#include "User.hpp"
#include "Business.hpp"
#include "Product.hpp"
#include "Transaction.hpp"
#include "Client.hpp"
#include "UI.hpp"


/* Check for valid name
 * +3 letters
 */

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


int main()
{
	User	*user = new User("Guest123");

	string	businessName;

	businessName = initBsn();
	cout << GREEN << "Creating Business: " << businessName << ENDC << endl;
	Business *bsn = new Business(user, businessName);
	
	cout << "Now let's start by listing your first product\n";

	bsn->createProduct();
	


	/*
	cout << "Entering Loop, please know that you can press 0 anytime to quit\n";
	string input;
	while(true)
	{
		cout << "blablabla mssg: Index of products\n";
		cin >> input;
		if (input == "0")
			break;
	} */

	uiProduct(bsn);

	delete user;
	delete bsn;

	return (1);
}
