#include "Hospital.hpp"

void	Hospital::addPatient(string name)
{
	Patient	*p = new Patient(name);
	_patients.push_back(p);
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
