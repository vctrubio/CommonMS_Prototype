#include "Library.hpp"

void		init(Library *lib)
{
	string	input;

	cout << " Please type '/init' to begin the server.\n|";
	while(getline(cin, input))
	{
		if (input == "/init")
		{
			// fetchData || API
			lib->parse("demo.csv");
			return ;
		}
		else
			cout << "|";
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
