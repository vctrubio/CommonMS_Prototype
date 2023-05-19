#include "../incl/Hospital.hpp"

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

void	Hospital::dDoctor(Doctor *d)
{
	d->archive();
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

void	Hospital::appCreate(Hospital *h, Doctor *d, Patient *p)
{
	p->addApp(new Appointment(d, p, availableRoom()));
}

void	appComplete(Appointment *app)
{
	app->complete();
}
