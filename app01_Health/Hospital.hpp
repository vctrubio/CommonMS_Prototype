#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "../Headers.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"
#include "Room.hpp"
#include "Appointment.hpp"

class Doctor;
class Patient;
class Room;
class Appoitment;

class Hospital
{
	vector<Patient*>	_patients;
	vector<Doctor*>		_doctors;
	//how to define appointments, tuple? map? vector?
public:
	Hospital(){cout << "Hospital created\n";};
	~Hospital();

	void	addDoctor(Doctor *d){_doctors.push_back(d);};
	void	dDoctor(Doctor *d);
	//void	dUDoctor(Doctor *d);

	void	addPatient(string name);
	void	addPatient(Patient *p);
	void	dPatient(Patient *p){p->_archived = true;};
	void	dUPatient(Patient *p){p->_archived = false;};

	void	upPatient(Patient *p){p->_ingr = true;};
	void	downPatient(Patient *p){p->_ingr = false;};

	void	printPatients(){cout << "Printing ALL Patients\n-----------------\n"; for (auto i : _patients){cout << *i;}; cout << "-----------------\n";};
	void	printDoctors(){cout << "Printing ALL Doctors\n-------------------\n"; for (auto i : _doctors){cout << i;}; cout << "------------------\n";};
};

#endif
