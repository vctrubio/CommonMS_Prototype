#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "../Headers.hpp"
#include "Hospital.hpp"


//define enum for speciality.

enum	speciality
{
	UNKNOWN = 0,
	TEETH = 1,
	HEART = 2,
	BONES = 3,
	BRAIN = 4
};

class Hospital;

class Doctor
{
	static unsigned int		s_count;
	unsigned int			_id;
	string					_name;
	enum speciality			_spc;	
	
	bool					_archive;
public:
	Doctor(string name, Hospital *h);
	~Doctor(){};

	void					archive(){_archive = true;};
	void					uArchive(){_archive = false;};

	int						id(){return _id;};
	string					name(){return _name;};

    friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
    {
        os << "Doctor ID: " << doctor._id << "\n";
        os << "Name: " << doctor._name << "\n";
        os << "Speciality: " << doctor._spc << "\n";
        os << "Archive: " << (doctor._archive ? "Yes" : "No") << "\n";
        return os;
    }
};


#endif
