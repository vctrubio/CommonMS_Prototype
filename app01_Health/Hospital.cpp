#include "Hospital.hpp"
#include "parseCsv.hpp"

static bool	strToBool(string b)
{
	if (b == "false")
		return false;
	return true;
}

void		Hospital::loop()
{
	string	input;

	system("clear");
	cout << "UI To SHOW....\n";

	cout << ">";
	while (getline(cin, input))
	{
		if (input == "break")
			break;
		cout << ">";
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
		{
			cout << "TESTING FOUND : " << i->id() << " : " << id << " NAME : " << i->name() << endl;
			return i;
		}
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
	_patients.clear();
	_doctors.clear();
}
