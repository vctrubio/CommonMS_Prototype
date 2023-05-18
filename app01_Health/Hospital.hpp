#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "../Headers.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"
#include "Room.hpp"

class Doctor;
class Patient;
class Room;

class Hospital
{
	map<int, Patient*>			_patients;
	vector<Doctor*>				_doctors;
	array<Room*, 40>			_rooms; //1-20 is for rest, 21-40 is for appointments
	vector<string>				cmds;
public:
	Hospital();
	~Hospital();

	Doctor	*idDoctor(int id);
	Doctor	*idDoctor(int id, string name);
	Doctor	*idDoctor(string name);
	Patient	*idPatient(int id);
	Doctor	*rtnDoctor(){
		try
		{
			return _doctors.front();
		}
		catch(const std::exception& e)
		{
			cout << RED << "Error: " << ENDC << e.what() << endl;
		}
		return nullptr;
	};

	bool	archivePatient(int id);
	bool	archiveDoctor(int id);
	
	void	addDoctor(Doctor *d){_doctors.push_back(d);};
	void	dDoctor(Doctor *d);
	//void	dUDoctor(Doctor *d);
	
	bool	doctorIdExist(int id);

	void	updatePCount();
	void	addPatient(string name);
	void	addPatient(vector<string> name);
	void	addPatient(Patient *p);
	void	dPatient(Patient *p){p->_archived = true;};
	void	dUPatient(Patient *p){p->_archived = false;};

	void	upPatient(Patient *p){p->_ingr = true;};
	void	downPatient(Patient *p){p->_ingr = false;};

	void	printPatients();
	void	printDoctors();
	
	void	loop();
	void	runloop();
	void	uCreatePatient();
	void	uCreateDoctor();
	
	Room	*availableRoom();
	void	appCreate(Hospital *h, Doctor *d, Patient *p);
	void	uiApp(vector<string>::iterator it);
	
	int		askID(int mode);


	void	appComplete(Appointment *app);

};

bool	validatePatient(vector<string> data);
#endif
