#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include "../Headers.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"

//belongs to a hospital obvs.....
//rooms later implementation


class Doctor;
class Patient;

class Appointment
{
	Doctor	*_doctor;
	Patient	*_patient;

	bool	_status;
	string 	dateTimeStr;
	time_t	_dateTime; //possible of 4 slots. 
public:
	Appointment(Doctor *doctor, Patient *patient);
	~Appointment(){};

	void	complete(){_status = true;};
	bool	status(){return _status;};

    Doctor	*getDoctor(){return _doctor;};
    Patient	*getPatient(){return _patient;};
	string	getTime(){return dateTimeStr;};
};

#endif
