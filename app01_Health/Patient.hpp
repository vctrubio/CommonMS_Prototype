#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "../Headers.hpp"

class Patient
{
	unsigned int	_id;
	string			_name;
	//history ...
	//alta? baja?? 
	bool			_state;
public:
	Patient(){};
	~Patient(){};
};

#endif
