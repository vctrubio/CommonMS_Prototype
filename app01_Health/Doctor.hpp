#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "../Headers.hpp"


//define enum for speciality.

enum	speciality
{
	TEETH = 1,
	HEART = 2,
	BONES = 3,
	BRAIN = 4
};

class Doctor
{
	unsigned int	_id;
	string			_name;
	enum speciality	_spc;	
public:
	Doctor(){};
	~Doctor(){};
};

#endif
