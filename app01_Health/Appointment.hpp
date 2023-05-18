#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include "../Headers.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"
#include "Room.hpp"
#include "Surgery.hpp"

class Surgery;
class Doctor;
class Patient;
class Room;

class Appointment
{
	Doctor	*_doctor;
	Patient	*_patient;

	bool	_status;
	string 	dateTimeStr;
	time_t	_dateTime; //possible of 4 slots.

	Surgery	*_surgery;
public:
	Appointment(Doctor *doctor, Patient *patient, Room *room);
	~Appointment(){};

	void	complete(){_status = true;};
	bool	status(){return _status;};

    Doctor	*getDoctor(){return _doctor;};
    Patient	*getPatient(){return _patient;};
	string	getTime(){return dateTimeStr;};

	string	csv();
};

std::ostream& operator<<(std::ostream& os, Appointment& appointment);

//there needs to be an inheritance of appointment 
//- one for checkup- no dado de baja
//- one for surgery- si dado de bajo
#endif
