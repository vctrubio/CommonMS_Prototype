#include "../Headers.hpp"
#include "User.hpp"
#include "Business.hpp"
#include "Product.hpp"


/* Check for valid name
 * +3 letters
 */

void	initBsn()
{
	string	input;

	cout << "Welcome to Common Solutions\n";
	cout << "To begin, please name your Business\n";
	cout << "ie: Tom's Garage";
	
	while(true)
	{
		cin >> input;
		if (input.length() >= 3)
			break;
		cout << "For soimplicity, it must be more than 3 characters\nAnd please, be careful(;\n";
	}
	

	return input;
}

int main()
{
	User	*user = new User("User1");

	string	businessName();

	businessName = initBsn();
	cout << "Creating Business: " << businessName << endl;



	delete user;

	return (1);
}
