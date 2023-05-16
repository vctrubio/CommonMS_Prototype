#include "TestingApiChatGpt.hpp"
#include <curl/curl.h>

#include "Hospital.hpp"
#include "User.hpp"
#include "UIMsg.hpp"


//if av = patient, init patient
//admin = hospital (password under git ignore.GNL to recieve PASSWORD="underground"
//doctor = Name && ID

enum ModeUI {
	ERROR = -1,
	ADMIN = 1,
	DOCTOR = 2,
	PATIENT = 3
};

ModeUI		init(char **av)
{
	if (strcmp(*av, "admin") == 0)
		return ADMIN;
	if (strcmp(*av, "doctor") == 0)
		return DOCTOR;
	if (strcmp(*av, "patient") == 0)
		return PATIENT;
	return ERROR;
}

Doctor		*initDoctor(string nameParam, Hospital *hospital)
{

	return new Doctor(nameParam, hospital);
}

void		uiDoctor(Hospital *hospital)
{
	Doctor	*doctor;
	string	input;

	cout << "I see... So you think you work here.\n";
	cout << "Please provide your #id.\n>";
	while (cin >> input)
	{
		if (input.length() > 0)
		{
			try 
			{
				initDoctor(input, hospital);
			}
			catch(runtime_error &e)
			{
				cout << RED << "Sorry " << ENDC << e.what() << " does NOT work here.\n Talk to admin if you believe there is a problem by typing ./healthcare admin request_to_work_here <your_name>" << endl;
			}
		}
		cout << ">";
	}

	//find doctor
	//UI MSG interface
}

int main(int ac, char **av)
{
	ModeUI		input;
	Hospital	*hospital = new Hospital();
	User		*user;

	if (ac <= 1)
	{
		msgErrorArgumentCount();
		return -1;
	}
	else
	{
		input = init(++av);
		if (input < 0)
		{
			cerr << RED << "Initialization Error.\n" << ENDC;
			cout << "'admin' 'patient' or 'doctor' not recieved as an argument.\n\n";
			return -1;
		}
	}

	if (input == PATIENT) 
		user initPatient(av[1]);
	if (user) // if user not found in DB
		hospital->addPatient(user);

	if (input == DOCTOR)
		uiDoctor(hospital);

	delete hospital;
	return 1;
}
















