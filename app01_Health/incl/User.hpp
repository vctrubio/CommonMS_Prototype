#ifndef USER_HPP
#define USER_HPP

#include "../../Headers.hpp"

#include "Patient.hpp"
#include "Hospital.hpp"

#include "Appointment.hpp"

class Patient;
class Hospital;
class Appointment;

class User : public Patient
{
public:
	User(string name):Patient(name){};
	~User(){};

	void	ui(Hospital *h);

void		uiUserPannel();
};
User		*initUser();
User		*initUser(string av, Hospital *h);

bool 		isNumeric(const string &str);
#endif
