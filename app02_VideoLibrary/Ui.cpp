#include "Ui.hpp"

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
        cout << RED << "ERROROROROROROROROR\n"; //need to trim.
        return 0;
    }
    if (*str)
        c = *(*str)++;
    return c;
}
