#include "User.hpp"


// void	uiPatient(Patient *p)
// {
// 	string alta = p->ingr()? "alta" : "baja";
	
// 	cout << "-----------------------------\n";
// 	cout << "| " << p->id() << " | " << p->name() << " | ";
// 	cout << alta << " | History [" << p->appointments.size() << "] \n";
// 	cout << " - - - - - - - - - - - - - - \n";
// 	cout << "|'new' for a new appointment|\n";
// 	cout << "|'chat' to talk to a doctor |\n";
// 	cout << "|'exit' to leave            |\n";
// 	cout << "----------------------------\n";


// 	if (p->ingr())
// 	{
// 		cout << ":Currently in Room X\n";
// 	}
// }


void	uiUser()
{

}

void	User::ui(Hospital *h)
{
	string input;

	cout << ">>";
	while(getline(cin, input))
	{
		if (input == "back" || input == "exit" || input == "0")
			return ;
		
		cout << ">>";
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
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "ERROR: " << ENDC << e.what() << '\n';
	}

	return ptr;
}

