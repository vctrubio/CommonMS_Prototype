#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "../Headers.hpp"
#include "Hospital.hpp"

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
	Doctor(unsigned int id, string name, int spc, bool archived, Hospital *h);
	~Doctor(){cout << RED << "-1" << ENDC " Doctor: " << _name << endl;};

	void					updateDCount(unsigned int i){s_count = i;};
	void					archive(){_archive = true;};
	void					uArchive(){_archive = false;};
	bool					isArchive(){return _archive;};
	int						id(){return _id;};
	string					name(){return _name;};
	string					rtnCsv();

	void					loop(Hospital *h);

    friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
    {
        os << "Doctor ID: " << doctor._id << "\n";
        os << "Name: " << doctor._name << "\n";
        os << "Speciality: " << doctor._spc << "\n";
        os << "Archive: " << (doctor._archive ? "Yes" : "No") << "\n";
        return os;
    }
};

void		uiADoctor(Doctor *ptr);

#endif
