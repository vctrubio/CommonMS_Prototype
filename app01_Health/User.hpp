#ifndef USER_HPP
#define USER_HPP

#include "../Headers.hpp"

#include "Patient.hpp"

class Patient;

class User : public Patient
{
public:
	User(string name):Patient(name){};
	~User(){};
};

#endif
