#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "../Headers.hpp"
// #include "Appointment.hpp"

class Appointment;

class Patient
{
	static unsigned int		s_count;
	friend class Hospital;

	unsigned int			_id;
	string					_name;
	//history ...
	bool					_ingr; //ingresado
	bool					_archived;

	vector<Appointment*>		_appointments;
public:
	Patient(string name):_id(s_count++),_name(name){_archived = false; _ingr = true;};
	Patient(unsigned int id, string name, bool ingr, bool archived):_id(id), _name(name){_archived = archived; _ingr = ingr;};
	virtual ~Patient(){};

	string	name(){return _name;};
	unsigned int	id(){return _id;};
	string	rtnCsv();

	friend std::ostream& operator<<(std::ostream& os, const Patient& patient)
	{
		os << "Patient ID: " << patient._id << "\n";
		os << "Name: " << patient._name << "\n";
		os << "Ingress: " << (patient._ingr ? "Yes" : "No") << "\n";
		os << "Archived: " << (patient._archived ? "Yes" : "No") << "\n";
		return os;
	}
};

//FRIENDS because i want to give hospital/admin full control to private. And not accesible to outsiders...
#endif
