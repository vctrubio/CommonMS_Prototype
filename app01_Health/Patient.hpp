#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "../Headers.hpp"

class Patient
{
	friend class Hospital;

	static unsigned int		s_count;
	unsigned int			_id;
	string					_name;
	//history ...
	bool					_ingr; //ingresado
	bool					_archived;
public:
	Patient(string name):_name(name){_archived = false; _ingr = true; cout << "P added\n";};
	~Patient(){cout << "P deleteed\n";};

};

//FRIENDS because i want to give hospital/admin full control to private. And not accesible to outsiders...
#endif
