#include "Doctor.hpp"

unsigned int Doctor::s_count = 1;


void		uiADoctor(Doctor *ptr)
{
   string input;

    if (!ptr)
        return;
    cout << ptr;
    cout << "------------------------------------------n>";
    cout << "CMDS: archive, unarchive, back\n>";

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
        else
            cout << ptr->name() << "|>";
    }
}

void	Doctor::loop(Hospital *h)
{
	cout << "-------------------------------\n";
	cout << "| Welcome Dct. " << _name << "\n";
	cout << "| You have X pending request |\n";
	cout << "------------------------------\n";
	cout << "|'exit' to leave             |\n";
	cout << "-----------------------------\n";

	string input;
	cout << ">";
	while (getline(cin, input))
	{   
		if (input.length() > 0)
        {
			cout << ".....kl\n";
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