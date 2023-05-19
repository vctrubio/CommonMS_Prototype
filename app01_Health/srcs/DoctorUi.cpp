#include "../incl/Doctor.hpp"

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

