#include "Hospital.hpp"

Hospital	&Hospital()
{
	static class Hospital hospital;

	return hospital;
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
	//before deleting, must store database.....
	cout << RED << "DECONGTRUCT\n" << ENDC;
	for (auto i : _patients)
		delete i;
	for (auto i : _doctors)
		delete i;
	_patients.clear();
	_doctors.clear();
}
