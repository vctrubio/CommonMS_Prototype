#ifndef USER_HPP
#define USER_HPP

#include "../Headers.hpp"

#include "Patient.hpp"
#include "Hospital.hpp"

class Patient;
class Hospital;

class User : public Patient
{
public:
	User(string name):Patient(name){};
	~User(){};

	void	ui(Hospital *h);
};
User		*initUser();
User		*initUser(string av, Hospital *h);

#endif
