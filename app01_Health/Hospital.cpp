#include "Hospital.hpp"

Doctor	*Hospital::idDoctor(int id, string name)
{
	for (auto i : _doctors)
	{
		if (i->id() == id)
		{
			if (i->name() == name)
				return i;
			else
				cout << RED << "ERROR: " << ENDC << " Doctor credentials ≠\n";
			break;
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

void	Hospital::addPatient(string name)
{
	Patient	*p = new Patient(name);
	_patients.push_back(p);
}

void	Hospital::addPatient(Patient *p)
{
	_patients.push_back(p);
}

void	Hospital::dDoctor(Doctor *d)
{
	d->archive();
}

Hospital::~Hospital()
{
	//before deleting, must store database..... for next usage 
	cout << RED << "DECONGTRUCT\n" << ENDC;
	for (auto i : _patients)
		delete i;
	for (auto i : _doctors)
		delete i;
	_patients.clear();
	_doctors.clear();
}
