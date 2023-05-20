#include "../incl/Library.hpp"

void		init(Library *lib)
{
	string	input;
	string	name;

	cout << " Please type '/init' to begin the server.\n|";
	while(getline(cin, input))
	{
		if (input == "/init")
		{
			mkdir("maps", 0744);
			lib->parse("demo.csv");
			system("clear");
			cout << GREEN << " Connected." << ENDC << "\n Give us your name to save your high score.\n|";
			while (getline(cin, name))
			{
				if (name.length() > 0)
				{
					lib->setUser(name);
					return ;
				}
				cout << RED <<  "|" << ENDC;
			}
		}
		else
			cout << RED <<  "|" << ENDC;
	}
}

int main()
{
	Library		lib;

    system("clear");
    welcome();
	init(&lib);
	lib.loop();
	return 1;
}
