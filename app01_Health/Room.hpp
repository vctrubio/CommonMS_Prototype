#ifndef ROOM_HPP
#define ROOM_HPP

#include "../Headers.hpp"
#include "Appointment.hpp"


class Appointment;

class Room
{
	int			_nb;
	bool		_available;
	Appointment	*_appointment;
public:
	Room(int n):_nb(n), _available(true){};
	Room(int n, Appointment *app):_nb(n), _available(false), _appointment(app){};


	void	toggle(){_available = !_available;};
	~Room(){};
};

#endif
