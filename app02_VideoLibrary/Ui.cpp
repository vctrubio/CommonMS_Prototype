#include "Ui.hpp"

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


void	putLine(string &out, char c)
{
	for (int size = 0; size < WIDTH + 1;) //topic
	{
		if (size == 0 || size == WIDTH)
			out += "|";
		else
			out += c;
		++size;
	}
	out += "\n";
}


void	putLeft(string in, string &out, char c)
{
	int size; 

	for (size = 0; size < WIDTH + 2;) //topic
	{
		if (size == 0 || size == WIDTH + 1)
			out += "|";
		else if (size <= in.length() - 1)
		{
			out += in;
			size += in.length();
		}
		else
			out += c;
		++size;
	}
	out += "\n";
} 

void	putUnderScore(string &out)
{
	int i = 0;
	for (int size = 0; size <= WIDTH;) //topic_underline
	{
		if (size == 0 || size == WIDTH)
			out += "|";
		else
		{
			if (i % 2 == 0)
				out += '-';
			else
				out += ' ';
			i++;
		}
		++size;
	}
	out += "\n";
}

char        itStr(char **str)
{
    char    c;

    if (strlen(*str) > WIDTH)
    {
        cout << RED << "EREORR\n"; //need to trim.
        return 0;
    }
    if (*str)
        c = *(*str)++;
    return c;
}
