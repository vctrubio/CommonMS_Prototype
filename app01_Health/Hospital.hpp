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
	Hospital(){};
	~Hospital();

	void	addPatient(string name);
	void	dPatient(Patient *p){p->_archived = true;};
	void	dUPatient(Patient *p){p->_archived = false;};

	void	upPatient(Patient *p){p->_ingr = true;};
	void	downPatient(Patient *p){p->_ingr = false;};

};

#endif
