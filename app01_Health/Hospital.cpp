#include "Hospital.hpp"

static bool	strToBool(string b)
{
	if (b == "false")
		return false;
	return true;
}

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

void	Hospital::dDoctor(Doctor *d)
{
	d->archive();
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

void	Hospital::updateCount()
{
	int	big = 1;
	for (auto i : _patients)
	{
		if (i.first > big)
			big = i.first;
	}
	Patient::s_count = big;
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
		while (getline(fileP, line))
		{
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
		while (getline(fileD, line))
		{
			vector<string>	tmp;
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
				tmp.push_back(data);
			// if (validateDoctor(tmp))
			// 	Doctor *d = new Doctor(123, "boby", 1, false, this); //OH FK
			tmp.clear();
		}
		fileD.close();
	}
	else
		cout << RED << "ERROR" << ENDC << " not able to parse doctorCSV\n";

	if (!_patients.empty())
		updateCount();
	// if (!_doctors.empty())
	// 	updateDCount(_doctors.size());
}

void	addtoCSV(int id, Patient *p)
{
	ifstream	fileP("patients.csv");
	vector<int>	tmp;
	if (fileP.is_open())
	{
		string line;
		while (getline(fileP, line))
		{
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
			{
				tmp.push_back(stoi(data));
				break;
			}
		}
		fileP.close();
	}
	for (auto i : tmp)
	{
		if (i == id)
			return ;
	}

	ofstream	fileWrite("patients.csv");
	if (cout << fileWrite.is_open())
	{
		fileWrite << p->rtnCsv();
		fileWrite.close();
	}
}

Hospital::~Hospital()
{
	cout << RED << "DECONGTRUCT: " << ENDC << "patient size = " << _patients.size() << endl;
	for (auto i : _patients)
	{
		addtoCSV(i.first, i.second);
		delete i.second;
	}
	for (auto i : _doctors)
		delete i;
	_patients.clear();
	_doctors.clear();
}



// vector<string>	fileToVector(ifstream file)
// {
// 	vector<string>	tmp;
// 	if (file.is_open())
// 	{
// 		string line;
// 		while (getline(file, line))
// 		{
// 			stringstream	ss(line);
// 			string			data;
// 			while (getline(ss, data, ','))
// 				tmp.push_back(data);
// 		}
// 		file.close();
// 	}
// 	return tmp;
// }
