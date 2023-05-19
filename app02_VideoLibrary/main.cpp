#include "Library.hpp"

void	welcome()
{
    char    *str = strdup("");
	string	mssg = GREEN;
	mssg += " Connected\n";
	mssg += ENDC;
    mssg += "|IMPORTANT! Please provide a big enough screen to properly view the Library; This message should appear in a single line|"; //120 WIDTH
    mssg += "\n";
	putUnderScore(mssg);
	putLeft(" CMDS. They start with /CMD followed with options defined [option]", mssg, 32);
	putLeft("/home is home", mssg, 32);
	putLeft("/back is back", mssg, 32);
	putLeft("/filter [top][view]", mssg, 32);
	putLeft("/help to view this message again", mssg, 32);
	putLeft("/exit to safely eject", mssg, 32);
	putLine(mssg, '-');
	cout << mssg;	
}

void		box(string header)
{
	string	buffer;

	buffer += YELLOW;
	putLeft(header, buffer, 32);
	buffer += ENDC;
	putLine(buffer, '-');
	
	cout << buffer;
}

void		init(Library *lib)
{
	string	input;

	cout << "Please type '/init' to begin the server.\n";
	while(getline(cin, input) && lib->online())
	{
		if (input == "/exit")
			lib->exit();
		else if (input == "/init")
		{
			// fetchData
			return ;
		}
		cout << "|";
	}
}

int main()
{
	Library		lib;

    system("clear");
    welcome();
	init(&lib);
	//lib.loop();
	return 1;
}