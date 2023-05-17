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

	//equal operator to compate one to another.
};

User		*initUser();
bool 		isNumeric(const string &str);
#endif
