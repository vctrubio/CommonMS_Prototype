#ifndef ROOM_HPP
#define ROOM_HPP

#include "../Headers.hpp"
#include "Appointment.hpp"

class Appointment;

class Room
{
	int						_nb;
	bool					_available;
	Appointment				*_appointment;
public:
	Room(int n):_nb(n), _available(true), _appointment(nullptr){};
	//Room(int n, Appointment *app):_nb(n), _available(false), _appointment(app){};

	int		nb(){return _nb;};
	bool	available(){return _available;};
	void	toggle(){_available = !_available;};
	void	addApp(Appointment *app){_appointment = app; _available = false;};

	string		info();
	Appointment	*appointment(){return _appointment;};
	~Room(){
		/*if (_appointment)
		{
			delete _appointment;
		}*/
	};
};


#endif
