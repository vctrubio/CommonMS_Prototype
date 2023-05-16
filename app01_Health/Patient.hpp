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
	Patient(string name):_name(name){_archived = false; _ingr = true; cout << "P " << _name << " added\n";};
	virtual ~Patient(){cout << "P deleteed\n";};

	string	name(){return _name;};
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
