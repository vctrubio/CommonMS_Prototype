#include "Doctor.hpp"

unsigned int Doctor::s_count = 1;

void		uiADoctor(Doctor *ptr)
{
   string input;

 	if (!ptr)
        return;

    if (ptr->isArchive())
        cout << RED;
    else
        cout << GREEN;
    cout << ptr->name() << ENDC << " |'archive', 'unarchive', 'back'\n>";

    while (getline(cin, input))
    {
        if (input.length() > 0)
        {
			if (input == "back")
                break;
            if (input == "archive")
                ptr->archive();
            if (input == "unarchive")
				ptr->uArchive();
        }
 		if (ptr->isArchive())
       		cout << RED;
    	else
       	 	cout << GREEN;
   		cout << ptr->name() << ENDC << " |'archive', 'unarchive', 'back'\n>";

  
    }
}

void	Doctor::loop(Hospital *h)
{
	if (_archive)
	{
		cout << RED << "Sorry you don't have permision to be here.\n" << ENDC;
		return ;
	}
	cout << "-------------------------------\n";
	cout << "| Welcome Dct. " << _name << "\n";
	cout << "| You have 0 pending request |\n";
	cout << "| Please come back later     |\n";
	cout << "------------------------------\n";
	cout << "|'exit' to leave             |\n";
	cout << "|'quit' to quit your job     |\n";
	cout << "-----------------------------\n";

	string input;
	cout << ">";
	while (getline(cin, input))
	{   
		if (input.length() > 0)
        {
			if (input == "quit")
			{
				archive();
				return ;
			}
        }
        else
            cout << ">";
	}
}

Doctor::Doctor(string name, Hospital *h):_name(name)
{
	_archive = false;
	_spc = UNKNOWN;
	_id = s_count++;
	h->addDoctor(this);
}

Doctor::Doctor(unsigned int id, string name, int spc, bool archived, Hospital *h):
_id(id), _name(name), _archive(archived)
{
	_spc = static_cast<speciality>(spc);
	h->addDoctor(this);
}

string	Doctor::rtnCsv()
{
	string str = to_string(_id);
	str += "," + _name + ",";
	str += to_string(_spc);
	str += ",";
	str += (_archive? "true" : "false");
	str += "\n";
	return str;
}

void	Doctor::updateDCount(Hospital *h)
{
	int big = _id;
	for (auto i : h->allDoctors())
	{
		if (i->id() > big)
			big = i->id();
	}
	s_count = big + 1;
}

bool	validateDoctor(vector<string> data)
{
	if (data.size() != 4)
		return false;
	for (auto c : data[0])
	{
		if (!isdigit(c))
			return false;
	}
	for (auto c : data[1])
	{
		if (!isascii(c))
			return false;
	}
	if (!isdigit(data[2][0])) //or not enum range
		return false;
	if (data[3] != "true" && data[3] != "false")
	    return false;
	return true;
}
