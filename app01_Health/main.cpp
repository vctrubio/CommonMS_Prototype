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

Doctor		*initDoctor(string id, Hospital *hospital)
{
	string	input;
	int		idSearch;

	if (!isNumeric(id))
			throw runtime_error(id + " not valid.");

	idSearch = stoi(id);
	cout << "What is your Full Name.\n>";
	while (getline(cin, input))
	{
		if (input.length() > 0)
		{
			return (hospital->idDoctor(idSearch));	
			break;
		}
		cout << ">";
	}
	return nullptr;
}

void		uiDoctor(Hospital *hospital)
{
	Doctor	*doctor;
	string	input;

	cout << "I see... So... you think you work here.\n";
	cout << "Please provide your #id.\n>";
	while (getline(cin, input))
	{
		if (input.length() > 0)
		{
			try 
			{
				doctor = initDoctor(input, hospital);
				break ;
			}
			catch(runtime_error &e)
			{
				cout << RED << "Sorry " << ENDC << e.what() << " does NOT work here.\n Talk to admin if you believe there is a problem by typing ./healthcare admin request_to_work_here <your_name>" << endl;
			}
		}
		cout << ">";
	}

	//find doctor OK
	if (doctor)
		cout << GREEN << doctor->name() << ENDC << " Welcome back... notification upcoming...\n";

}

int main(int ac, char **av)
{
	ModeUI		input;
	Hospital	hospital;
	User		*user;
	Doctor		*doctor = new Doctor("billy", &hospital);


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
		user = initUserPatient(av[1]);
	if (user) // if user not found in DB //if user 'iopdafasfasd' throws bus/segfault.......
		hospital.addPatient(user);

	if (input == DOCTOR)
		uiDoctor(&hospital);
	return 1;
}
















