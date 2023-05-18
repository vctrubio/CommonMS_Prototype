#include "Hospital.hpp"
#include "parseCsv.hpp"

Hospital::Hospital()
{
	string	rootDir = "db";
	string	patienFile = "patients.csv";
	string	doctorFile = "doctors.csv";
	
	mkdir(rootDir.c_str(), 0744);
	filesystem::current_path(rootDir);

	ifstream fileP(patienFile);
	if (fileP.is_open())
	{
		string line;
		// int i = 0;
		while (getline(fileP, line))
		{
			// if (i++ == 0)
			// 	continue;
			vector<string>	tmp;
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
				tmp.push_back(data);
			if (validatePatient(tmp))
				addPatient(tmp);
			tmp.clear();
		}
		fileP.close();
	}
	else
		cout << RED << "ERROR" << ENDC << " not able to parse patientCSV\n";

	ifstream fileD(doctorFile);
	if (fileD.is_open())
	{
		string line;
		// int i = 0; //later for header CSV
		while (getline(fileD, line))
		{
			// if (i++ == 0)
			// 	continue;
			vector<string>	tmp;
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
				tmp.push_back(data);
			if (validateDoctor(tmp))
			 	new Doctor((unsigned int)stoi(tmp[0]), tmp[1] , tmp[2][0], false, this); //OH FK
			tmp.clear();
		}
		fileD.close();
	}
	else
		cout << RED << "ERROR" << ENDC << " not able to parse doctorCSV\n";

	if (!_patients.empty())
		updatePCount();
	if (!_doctors.empty())
		_doctors.front()->updateDCount(_doctors.size());

	//Create rooms
	for (int i = 0; i < 40; i++)
		_rooms[i] = new Room(i + 1);
}

Hospital::~Hospital()
{
	cout << RED << "DECONGTRUCT: " << ENDC << "patient size = " << _patients.size() << endl;
	cout << RED << "DECONGTRUCT: " << ENDC << "Doctor size = " << _doctors.size() << endl;
	for (auto it = _patients.begin(); it != _patients.end(); ++it)
	{
		addtoCSV(it->first, it->second);
		delete it->second;
	}
	for (auto i : _doctors)
	{
		addtoCSV(i->id(), i);
		delete i;
	}
	for (auto i : _rooms)
		delete i;
	_patients.clear();
	_doctors.clear();
	//_rooms.clear();
}

static bool	strToBool(string b)
{
	if (b == "false")
		return false;
	return true;
}

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

//////////////////////////////////////////////////////////////////////////////////////
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
				cout << "Nothing to show>";
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
					cout << "trying to ...\n";
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

void	Hospital::runloop()
{
	for (auto it = cmds.begin(); it != cmds.end(); ++it)
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
				cout << it->info() << "-----------------\n";
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






//////////////////////////////////////////////////////////////////////////
bool	Hospital::archivePatient(int id)
{
	if (_patients.count(id) > 0)
	{
		_patients[id]->archive();
		cout << GREEN << "Success: "<< ENDC << _patients[id]->name() << endl;
		return true;
	}
	return false;
}

bool	Hospital::archiveDoctor(int id)
{
	for (auto i : _doctors)
	{
		if (i->id() == id)
		{
			i->archive();
			cout << GREEN << "Success: "<< ENDC << i->name() << endl;
			return true;
		}
	}
	return false;
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























//DOCTOR MAN
Doctor	*Hospital::idDoctor(int id, string name)
{
	for (auto i : _doctors)
	{
		if (i->id() == id)
		{
			if (i->name() == name)
				return i;
			else
				cout << RED << "ERROR: " << ENDC << " Doctor credentials: " << name << " ≠ " << i->name() << endl;
			return nullptr;
		}
	}
	cout << RED << "ERROR: " << ENDC << " Doctor with " << id << " not found.\n";
	return nullptr;
}

Doctor	*Hospital::idDoctor(string name)
{
	for (auto i : _doctors)
	{
		cout << "CHECKING :" << name << " : " << i->name() <<  endl;
		if (i->name() == name)
				return i;
	}
	cout << RED << "ERROR: " << ENDC << " Doctor with " << name << " not found.\n";
	return nullptr;
}

Doctor	*Hospital::idDoctor(int id)
{
	for (auto i : _doctors)
	{
		if (i->id() == id)
			return i;
	}
	cout << RED << "ERROR: " << ENDC << " Doctor with " << id << " not found.\n";
	return nullptr;
}

void	Hospital::dDoctor(Doctor *d)
{
	d->archive();
}

//PATIENT MAN
void	Hospital::addPatient(vector<string> name)
{
	if (_patients[stoi(name[0])] == 0)
	{
		Patient	*p = new Patient((unsigned int)stoi(name[0]), name[1], strToBool(name[2]), strToBool(name[3]));
		_patients[stoi(name[0])] = p;
	}
}

void	Hospital::addPatient(string name)
{
	Patient	*p = new Patient(name);
	_patients[p->_id] = p;
}

void	Hospital::addPatient(Patient *p)
{
	if (_patients.count(p->_id) == 0)
		_patients[p->_id] = p;
	else
		cout << RED << "Error." << ENDC << " Patient ID " << p->_id << " taken.\n";
}

bool	validatePatient(vector<string> data)
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
	if (data[2] != "true" && data[2] != "false")
	    return false;
	if (data[3] != "true" && data[3] != "false")
	    return false;
	return true;
}

void	Hospital::updatePCount()
{
	int	big = 1;
	for (auto i : _patients)
	{
		if (i.first > big)
			big = i.first;
	}
	big++;
	Patient::s_count = (unsigned int)big;
 }

bool	Hospital::doctorIdExist(int id)
{
	for (auto it = _doctors.begin(); it != _doctors.end(); ++it)
	{
		if ((*it)->id()== id)
			return false;
	}
	return true;
}

Patient	*Hospital::idPatient(int id)
{
	Patient *ptr = nullptr;
	try
	{
		ptr = _patients[id];
		
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Patient with ID " << id << " not found." << std::endl;
		return nullptr;
	}
	return ptr;
}

void	Hospital::printPatients()
{
	cout << "Patients [" << GREEN << _patients.size() << ENDC << "]\n";
	cout << "--------------------------------------\n";
	for (std::map<int, Patient*>::iterator it = _patients.begin(); it != _patients.end(); ++it)
	{
		if (it->second->isArchive())
			continue;
		cout << *(it->second);
		cout << "- - - - - - - - - - -\n";
	} 
	cout << "--------------------------------------\n";
}

void	Hospital::printDoctors()
{
	cout << "Doctors [" << GREEN << _doctors.size() << ENDC << "]\n";
	for (auto i : _doctors)
	{
		if (i->isArchive())
			continue;
		cout << *i;
		cout << "- - - - - - - - - - -\n";
	}
	cout << "--------------------------------------\n";
}

/////////////////////ROOMS & APPOINTMENT
void	Hospital::appCreate(Hospital *h, Doctor *d, Patient *p)
{
	p->addApp(new Appointment(d, p, availableRoom()));
}

void	appComplete(Appointment *app)
{
	app->complete();
}

Room	*Hospital::availableRoom()
{
	try
	{
		for (auto i : _rooms)
		{
			if (i->available())
				return i;
		}
		throw overflow_error("Hospital at FULL capacity.\n");
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
	return nullptr;
};