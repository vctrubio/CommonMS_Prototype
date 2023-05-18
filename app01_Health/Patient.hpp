#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "../Headers.hpp"

class Appointment;

class Patient
{
	friend class Hospital;

	static unsigned int		s_count;
	unsigned int			_id;
	string					_name;
	bool					_ingr; //ingresado
	bool					_archived;

	vector<Appointment*>	_appointments;
public:
	Patient(string name):_id(s_count++),_name(name),_appointments(vector<Appointment*>()){_archived = false; _ingr = false; cout << GREEN << "+1" << ENDC " Patient: " << _name << endl;};
	Patient(unsigned int id, string name, bool ingr, bool archived):_id(id), _name(name){_archived = archived; _ingr = ingr;};
	virtual ~Patient(){cout << RED << "-1" << ENDC " Patient: " << _name << endl;};

	string					name(){return _name;};
	unsigned int			id(){return _id;};
	bool					ingr(){return _ingr;};
	string					rtnCsv();

	void					archive(){_archived = true;};
	void					uArchive(){_archived = false;};

	void					alta(){_ingr = false;};
	void					baja(){_ingr = true;};
	vector<Appointment*>	appointments(){return _appointments;};

	void					addApp(Appointment *app){_appointments.push_back(app);};
	friend std::ostream& operator<<(std::ostream& os, const Patient& patient)
	{
		os << "Patient ID: " << patient._id << "\n";
		os << "Name: " << patient._name << "\n";
		os << "Ingress: " << (patient._ingr ? "Yes" : "No") << "\n";
		os << "Archived: " << (patient._archived ? "Yes" : "No") << "\n";
		return os;
	}

};

	void			uiPatient(Patient *ptr);
#endif
