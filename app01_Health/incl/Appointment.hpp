#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include "../../Headers.hpp"
#include "Doctor.hpp"
#include "Room.hpp"
#include "Surgery.hpp"

class Surgery;
class Doctor;
class Patient;
class Room;
class Surgery;

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
	~Appointment(){cout << "ANBOPDY SEE ME?: " << csv() << endl;};

	void	complete();
	bool	status(){return _status;};

    Doctor	*getDoctor(){return _doctor;};
    Patient	*getPatient(){return _patient;};
	string	getTime(){return dateTimeStr;};
	void	print();
	string	csv();
};

bool 				surgeryPro();
std::ostream&		operator<<(std::ostream& os, Appointment& appointment);
vector<time_t>      generateRandomTimes();
string    			dateToString(time_t date);
#endif
