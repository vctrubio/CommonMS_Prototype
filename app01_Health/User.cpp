#include "User.hpp"

bool isNumeric(const string &str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
			return false;
	}
	return true;
};

//search for user if av in database, by ID.
static User		*initUser(char *av)
{
	User	*ptr;
	int 	idSearch;

	if (!isNumeric(string(av)))
			throw runtime_error(string(av));

	//if map user not found, throw, user not found with ID: 
	idSearch = stoi(av);
	if (idSearch)
		cout << "YELLLOOW--ºn TODO MAPPING\n";
	else
		throw runtime_error(string(av));

	ptr = new User("Guest.123"); //should return guest MAPPED
	return ptr;
}

static User		*initUser()
{
	string input;

	cout << "Welcome to Common Health Care.\n";
	cout << "Start by giving us your name.\n>";

	cin >> input; //varify input..
	return (new User(input));
}

User		*initUserPatient(char *av)
{
	User	*user;
	try
	{
		if (av)
			user = (initUser(av));
		else
			user = (initUser());
	}
	catch (runtime_error &e)
	{
		cerr << RED << "Sorry " << ENDC << "User with ID "<< e.what() << " not found\n";
	}
	return user;
}

