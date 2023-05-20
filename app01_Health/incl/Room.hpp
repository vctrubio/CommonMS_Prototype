#ifndef ROOM_HPP
#define ROOM_HPP

#include "../../Headers.hpp"
#include "Appointment.hpp"

class Appointment;

class Room
{
	int						_nb;
	bool					_available;
	bool					_hasapp = false;
	Appointment				*_appointment;
public:
	Room(int n):_nb(n), _available(true), _appointment(nullptr){};

	int		nb(){return _nb;};
	bool	available(){return _available;};
	void	toggle(){_available = !_available;};
	void	check();
	bool	valid(){return _hasapp;};
	void	addApp(Appointment *app){_appointment = app; _available = false; _hasapp = true;};

	string		info();
	Appointment	*app(){return _appointment;};
	~Room(){};
};


#endif
