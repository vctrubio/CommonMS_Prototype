#include "../incl/User.hpp"

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
	bool in = ingr()? true : false;
	if (!in)
		cout << GREEN << "|" << ENDC;
	else
		cout << RED << "|" << ENDC;
	cout << name() << " |ID: " << id();
	cout << "\n-----------------------------------\n";
	cout << "|'view doctors'                     |\n";
	cout << "|'new' for new appointment          |\n";
	cout << "|'clear' make sure to check         |\n";
	cout << "|'back'||'exit'                     |\n";
	// cout << "|'chat' to talk to AI             |\n";
	cout << "- - - - - - - - - - - - - - - - - - \n";
	cout << "[" << appointments().size() << "]  Appointments                  \n";

	int count = 0;
	vector<Appointment*> ptr;
	for (auto i : appointments())
	{
		if (!i->status())
			ptr.push_back(i);
	}
	if (!ptr.empty())
	{
		cout << GREEN << "REMINDER: " << ENDC << "You have " << GREEN << ptr.size() << ENDC << " coming up.";
		cout << "\n- - - - - - - - - - - - - - - - - - \n";
		for (auto i : ptr)
		{
			cout << *i;
			cout << "\n- - - - - - - - - - - - - - - - - - \n";
		}
		cout << "\n-----------------------------\n";
		cout << "|'yes' to attend appointment   \n";
	}
	if (ingr())
		cout << "|'solicitud' || '1' for checkup            \n";
	cout << "\n-----------------------------\n";
}

void	User::ui(Hospital *h)
{
	string input;

	system("clear");
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
			h->appCreate(h->rtnDoctor(), this);
			continue;
		}
		else if (input == "clear")
		{
			ui(h);
			return ;
		}
		else if (input == "yes" && !appointments().empty())
		{
			if (ingr())
				cout << RED << "Sorry " << ENDC << " you are still not recovered from surgery.\n";
			else
			{
				for (auto i : appointments())
				{
					if (!i->status())
					{
						i->complete();
						break ;
					}
				}
			}
		}
		else if ((input == "solicitud" || input == "1") && ingr())
		{
			if (!surgeryPro())
			{
				alta();
				cout << GREEN << "Congratulations " << ENDC << "our specialist have checked you out.\n"; // of room
			}
			else
				cout << YELLOW << "Unfortunetly " << ENDC << "our medical staff still see you unfit.\n";
		}
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
