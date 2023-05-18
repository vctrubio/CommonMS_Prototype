#ifndef SURGERY_HPP
#define SURGERY_HPP

#include "../Headers.hpp"

#include "Appointment.hpp"
#include "Patient.hpp"

class Appointment;
class Patient;

class Surgery
{
	bool 		_complete;
	Patient* 	_patient;
	Patient* 	_doctor;
public:
	Surgery(Patient *p):_complete(false), _patient(p){};
	~Surgery(){};

	bool	complete(){return _complete;};
	void	isComplete(){_complete = true; _patient->alta();};
};

#endif
