#include "../incl/Hospital.hpp"

template<typename T>
void	addtoCSV(string name,  T *ptr)
{
	if (!ptr)
		return ;
	ofstream	fileWrite(name, ios::app);
	bool		check = filesystem::exists(name);
	if (fileWrite.is_open())
	{
		fileWrite << ptr->rtnCsv();
		fileWrite.close();
	}
}

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
		bool	firstLine = true;
		while (getline(fileP, line))
		{
			if (firstLine)
			{
				firstLine = false;
				continue;
			}
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
		bool	firstLine = true;
		while (getline(fileD, line))
		{
			if (firstLine)
			{
				firstLine = false;
				continue;
			}
			vector<string>	tmp;
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
				tmp.push_back(data);
			if (validateDoctor(tmp))
			 	new Doctor((unsigned int)stoi(tmp[0]), tmp[1] , tmp[2][0], (tmp[3] == "false" ? false : true), this); //OH FK
			tmp.clear();
		}
		fileD.close();
	}
	else
		cout << RED << "ERROR" << ENDC << " not able to parse doctorCSV\n";

	if (!_patients.empty())
		updatePCount();
	if (!_doctors.empty())
		_doctors.front()->updateDCount(this);

	for (int i = 0; i < 40; i++)
		_rooms[i] = new Room(i + 1);
}

Hospital::~Hospital()
{
	const char *patientFile = "patients.csv";
	const char *doctorFile = "doctors.csv";
	const char *appFile = "appointments.csv";

	ofstream fileApp(appFile, ios::app);
	if (fileApp.is_open())
	{
		if (fileApp.tellp() == 0)
			fileApp << "Patient,Doctor,Date,Completed,Surgery?\n";
		for (auto i : _rooms)
		{
			if (i->valid())
				fileApp << i->app()->csv();
		}
		fileApp.close();
	}

	ofstream fileP(patientFile);
	if (fileP.is_open())
	{
		fileP << "Id,Name,Ingressed,Archived\n";
		fileP.close();
	}
	for (auto it = _patients.begin(); it != _patients.end(); ++it)
	{
		addtoCSV<Patient>(patientFile, it->second);
		delete it->second;
	}

	ofstream fileD(doctorFile);
	if (fileD.is_open())
	{
		fileD << "Id,Name,Spcs,Archived\n";
		fileD.close();
	}
	for (auto i : _doctors)
	{
		addtoCSV<Doctor>(doctorFile, i);
		delete i;
	}

	_patients.clear();
	_doctors.clear();
}

//////////////////////////////////////////////////////////////////////////////////////
Doctor	*Hospital::rtnDoctor()
{
	if (_doctors.empty())
		return nullptr;

	auto tmp = _doctors;
	std::random_device rd;
	std::mt19937 gen(rd());	
	shuffle(tmp.begin(), tmp.end(), gen);
	return tmp.front();
};

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

void	Hospital::printPatients()
{
	cout << "Patients [" << GREEN << pSize() << ENDC << "]\n";
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
	cout << "Doctors [" << GREEN << dSize() << ENDC << "]\n";
	for (auto i : _doctors)
	{
		if (i->isArchive())
			continue;
		cout << *i;
		cout << "- - - - - - - - - - -\n";
	}
	cout << "--------------------------------------\n";
}

int		Hospital::pSize()
{
	int size = 0;

	for (auto i : _patients)
	{
		if (i.second->isArchive())
			continue;
		size++;
	}
	return size;
}

int		Hospital::dSize()
{
	int size = 0;

	for (auto i : _doctors)
	{
		if (i->isArchive())
			continue;
		size++;
	}
	return size;
}

bool	strToBool(string b)
{
	if (b == "false")
		return false;
	return true;
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
}
