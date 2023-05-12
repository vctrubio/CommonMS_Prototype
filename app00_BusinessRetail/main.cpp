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

std::mutex queueMutex; 

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


void	initInstruction()
{
	cout << "Entering Program |-> Instructions\nType:\n\tID# to see specific product\n\t'new' to add product\n\t0 or 'exit' to exit\n\t'back' to go back\n\t'open' to open your shop for business!\n";
	usleep(900000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
	cout << ".........\n";
	usleep(800000);
}

int main()
{
	User	*user = new User("Guest123");

	string	businessName;

	businessName = initBsn();
	cout << GREEN << "Creating Business: " << businessName << ENDC << endl;
	Business *bsn = new Business(user, businessName);
	
	cout << "................\nNow let's start by listing your first product\n";
	bsn->createProduct();

	// thread t(&initInstruction);
	// t.join();

	uiBsn(bsn);

	delete user;
	delete bsn;

	return (1);
}
