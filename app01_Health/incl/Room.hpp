#ifndef ROOM_HPP
#define ROOM_HPP

#include "../../Headers.hpp"
#include "Appointment.hpp"

class Appointment;

class Room
{
	int						_nb;
	bool					_available;
	Appointment				*_appointment;
public:
	Room(int n):_nb(n), _available(true), _appointment(nullptr){};

	int		nb(){return _nb;};
	bool	available(){return _available;};
	void	toggle(){_available = !_available;};
	void	check();
	void	addApp(Appointment *app){_appointment = app; _available = false;check();};

	string		info();
	Appointment	*appointment(){return _appointment;};
	~Room(){};
};


#endif
