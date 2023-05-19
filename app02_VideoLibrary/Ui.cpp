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
	putLeft(" CMDS. They start with /CMD or /ID to view single.", mssg, 32);
	putLeft("/sort to sort", mssg, 32);
	putLeft("/filter to filter with sql ", mssg, 32);
	putLeft("/all to !filter ", mssg, 32);
	putLeft("/ID to view ", mssg, 32);
	
	putLeft("/help to view this message again", mssg, 32);
	putLeft("/back to go back", mssg, 32);
	putLeft("/exit to safely eject", mssg, 32);
	putLine(mssg, '-');
	cout << mssg;	
}

void		box(vector<tuple<int, string>> obj, int &index)
{
	string	buffer;
	int count = 0;
	
	int flagIndex = true;
	for (auto it : obj)
	{
		tuple<int,string> 		ptr = it;
		const char				*tmp = (get<1>(ptr)).c_str();
		for (int i = 0; i <= get<0>(ptr); i ++)
		{
			if (i <= 1 || i == get<0>(ptr) && count < 1)
			{
				if (i == 0)
					buffer += "|";
				else if (i == 1 && flagIndex)
				{
					buffer += to_string(index);
					buffer += "|";
					i += to_string(index).length();
					flagIndex = false;
				}
				count++;
			}
			else if (*tmp)
				buffer += itStr(&tmp, 26);
			else
				buffer += 32;
		}
	}
	index++;
	buffer += "\n";
	putUnderScore(buffer);
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

char        itStr(const char **str, int limit)
{
    char    c;

    if (strlen(*str) > limit || !*str) //need to trim
        return 0;
    if (*str)
        c = *(*str)++;
    return c;
}
