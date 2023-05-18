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

void	User::uiUserPannel()
{
	bool in = ingr()? false : true;
	if (!in)
		cout << GREEN << "|" << ENDC;
	else
		cout << RED << "|" << ENDC;
	cout << name() << " | ";
	cout << "\n-----------------------------------\n";
	cout << "|'view doctors'                   |\n";
	cout << "|'new' for new appointment        |\n";
	cout << "|'histoy' for appointment history |\n";
	cout << "- - - - - - - - - - - - - - - - - - \n";
	cout << "[" << appointments.size() << "]  Appointments                  |\n";

	int count = 0;
	vector<Appointment*> ptr;
	for (auto i : appointments)
	{
		if (!i->status())
			ptr.push_back(i);
	}
	if (!ptr.empty())
	{
		cout << GREEN << "REMINDER: " << ENDC << "You have " << GREEN << ptr.size() << ENDC << " coming up.";
		for (auto i : ptr)
			cout << *i;
	}

	cout << "\n-----------------------------------\n";
}

void	User::ui(Hospital *h, int start)
{
	string input;

	system("clear");
	if (start)
	{
		cout << RED << "'exit' || '0' for exit\n" << ENDC; 
		cout << YELLOW << "'back' to go back\n" << ENDC; 
		cout << YELLOW << "clear to clear the screen\n" << ENDC; 
		cout << "-----------------------------------\n"; 
	}
	uiUserPannel();
	cout << ">";
	while(getline(cin, input))
	{
		if (input == "back" || input == "exit" || input == "0")
			return ;
		else if (input == "view doctors")
			h->printDoctors();
		else if (input == "new")
		{
			h->appCreate(h, h->rtnDoctor(), this);
			ui(h, 0);
			return ;
		}
		else if (input == "history")
			break ;
		else if (input == "clear")
		{
			ui(h, 0);
			return ;
		}
		
		// if (input == "yes" || "no" || appointment)
		else 
			cout << ">";
	}
}



User		*initUser()
{
	string input;

	cout << "Welcome to Common Health Care.\n";
	cout << "Start by giving us your name.\n>";

	cin >> input; //varify input..
	return (new User(input));
}

User		*initUser(string av, Hospital *h)
{
	User	*ptr;
	int 	idSearch;

	try
	{
		idSearch = stoi(av);
		ptr = static_cast<User*>(h->idPatient(idSearch));
		if (!ptr)
			throw runtime_error(av + " not valid.");
		cout << GREEN << "Welcome: " << ENDC << ptr->name() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "ERROR: " << ENDC << e.what() << '\n';
		return nullptr;
	}

	return ptr;
}

