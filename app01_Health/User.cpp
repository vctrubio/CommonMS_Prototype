#include "User.hpp"

bool isNumeric(const string &str)
{
	for (char c : str)
	{
		if (!isdigit(c))
			return false;
	}
	return true;
};

//search for user if av in database, by ID.
static User		*initUser(char *av)
{
	User	*ptr;
	int 	idSearch;


	if (idSearch)

		cout << "YELLLOOW--ºn TODO MAPPING\n";
	else
		throw runtime_error(string(av));

	ptr = new User("Guest.123"); //should return guest MAPPED
	return ptr;
}

User		*initUser()
{
	string input;

	cout << "Welcome to Common Health Care.\n";
	cout << "Start by giving us your name.\n>";

	cin >> input; //varify input..
	return (new User(input));
}

