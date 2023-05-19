#include "Hospital.hpp"

static void	uiAdmin()
{
	cout << "---------------------------\n";
	cout << "| Admin Menu | TYPE CMD   |\n";
	cout << "---------------------------\n";
	cout << "|'all patients/doctor'    |\n";
	cout << "|'new patient/doctor'     |\n";
	cout << "|'# <ID> patient/doctor'  |\n";
	cout << "|'archive #id patient'    |\n";
	cout << "|'rooms' to see all       |\n";
	cout << "|app #IDpatiant #IDdoctor'|\n";
	cout << "|app for app Managment    |\n";
	cout << "---------------------------\n";
}

void	Hospital::runloop()
{
	for (auto it = cmds.begin(); it != cmds.end();)
	{
		if (*it == "exit" || *it == "0" || *it == "back")
			return ;
		else if (*it == "new")
		{
			if (++it == cmds.end())
				break;
			if (*it == "patient")
				uCreatePatient();
			if (*it == "doctor")
				uCreateDoctor();
		}
		else if (*it == "all")
		{
			if (++it != cmds.end())
			{
				if (*it == "patients")
					printPatients();
				else if (*it == "doctors")
					printDoctors();
			}
		}
		else if (*it == "#")
		{
			if (++it != cmds.end())
			{
				try
				{
					int id = stoi(*it);
					if (++it != cmds.end())
					{
						if (*it == "patient")
							uiPatient(_patients[id]);
						else if (*it == "doctor")
							uiADoctor(idDoctor(id));
					}
				}
				catch(const std::exception& e)
				{
					cout << RED << "Error: " << ENDC << e.what() << endl;
				}
			}
		}
		else if (*it == "archive")
		{
			if (++it != cmds.end())
			{
				try
				{
					int id = stoi(*it);
					if (++it != cmds.end())
					{
						if (*it == "patient" && !archivePatient(id))
						{
							cout << RED << "Error: " << ENDC << " no patient #id " << id << endl;
						}
						else if (*it == "doctor" && !archiveDoctor(id))
							cout << RED << "Error: " << ENDC << " no doctor #id " << id << endl;
					}
				}
				catch (const std::exception& e)
				{
					cout << RED << "Error2: " << ENDC << e.what() << endl;
				}
			}
		}
		else if (*it == "rooms")
		{
			for (auto it : _rooms)
			{
				cout << it->info();
				cout << "-----------------\n";
			}
		}
		else if (*it == "app")
			uiApp(++it);
		return ;
	}
}

void		Hospital::loop()
{
	string	input;

	system("clear");
	uiAdmin();
	cout << GREEN <<  "…" << ENDC ">";
	while (getline(cin, input))
	{
		if (input == "break" || input == "exit" || input == "0")
			return ;
		if (input == "clear")
		{
			loop();
			return ;
		}
		else if (input.length() > 0)
		{
			stringstream	ss(input);
			string			tmp;
			while(getline(ss, tmp, ' '))
				cmds.push_back(tmp);
			runloop();
			cmds.clear();
		}
			cout << GREEN <<  "…" << ENDC ">";
	}
}

void	Hospital::uiApp(vector<string>::iterator it)
{
	if (it == cmds.end())
	{
		system("clear");
		string input;
		cout << "--------------------------\n";
		cout << "| 'back' | 'new' | 'show' |\n";
		cout << "--------------------------\n>";
		while (getline(cin, input))
		{
			if (input == "back" || input == "exit")
			{
				loop();
				return;
			}
			if (input == "show")
			{
				printPatients();
				printDoctors();
				continue;
			}
			else if (input == "new")
			{
				int patient = askID(1);
				if (patient < 0 )
					return ;
				int doctor = askID(2);
				if (doctor < 0)
					return ;
				try
				{
					new Appointment(idDoctor(doctor), idPatient(patient), availableRoom());
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				return ;
			}
			else
				cout << ">";
		}
	}
	else
	{
		try
		{
			Patient *p = idPatient(stoi(*it++));
			Doctor	*d = idDoctor(stoi(*it++));
			if (!p || !d)
				throw runtime_error("ID's not valid.");
			if (it == cmds.end())
				appCreate(this, d, p);
			else
				cout << RED << "SORRY" << ENDC << " too many cmds.\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void	Hospital::uCreatePatient()
{
	string	input;

	cout << YELLOW << "NEW" << ENDC << " Patient.\n";
	cout << "Name> ";

	while(getline(cin, input))
	{
		if (input.length() > 0)
		{
			Patient *ptr = new Patient(input);
			_patients[ptr->id()] = ptr;
			return ;
		}
		cout << ".....>";
	}
}

void	Hospital::uCreateDoctor()
{
	string	input;

	cout << YELLOW << "NEW" << ENDC << " Doctor.\n";
	cout << "Name> ";
	while(getline(cin, input))
	{
		if (input.length() > 0)
		{
			Doctor *ptr = new Doctor(input, this);
			cout << GREEN << "+1" << ENDC " Doctor: " << ptr->name() << endl;
			return ;
		}
		cout << ".....>";
	}
}

int		Hospital::askID(int mode)
{
	string	input;
	int		rtn;

	if (mode == 1)
		cout << "What Patient #ID> ";
	if (mode == 2)
		cout << "What Doctor #ID> ";
	while(getline(cin, input))
	{
		if (input.length() > 0)
		{
			if (input == "show")
			{
				if (mode == 1)
				{
					printPatients();
					cout << "So. What Patient #ID> ";
				}
				if (mode == 2)
				{
					printDoctors();
					cout << "So. What Doctor #ID> ";
				}
				continue;
			}
			if (input == "back" || input == "exit")
				return -1;
			try
			{
				rtn = (stoi(input));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			break;
		}
		if (mode == 1)
			cout << "What Patient #ID> ";
		if (mode == 2)
			cout << "What Doctor #ID> ";
	}
	return rtn;
}
