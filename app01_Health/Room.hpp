#ifndef ROOM_HPP
#define ROOM_HPP

#include "../Headers.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"

class Patient;
class Doctor;

class Room
{
	int		_nb;
	bool	_available;
	Patient	*_patient;
	Doctor	*_doctor;
public:
	Room(int n):_nb(n), _available(true){};
	Room(int n, Patient *p, Doctor *d):_nb(n), _available(false), _patient(p), _doctor(d){};
	~Room(){};
};

#endif
