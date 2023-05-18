
#include "Hospital.hpp"
#include "User.hpp"
#include "UIMsg.hpp"
#include "Appointment.hpp"


//if av = patient, init patient
//admin = hospital (password under git ignore.GNL to recieve PASSWORD="underground"
//doctor = Name && ID

enum ModeUI {
	ERROR = -1,
	ADMIN = 1,
	DOCTOR = 2,
	PATIENT = 3,
	IDPATIENT = 4
};

ModeUI		init(char **av)
{
	if (strcmp(*av, "admin") == 0)
		return ADMIN;
	if (strcmp(*av, "doctor") == 0)
		return DOCTOR;
	if (strcmp(*av, "patient") == 0 && !(*(av + 1)))
		return PATIENT;
	if (strcmp(*av, "patient") == 0)
		return IDPATIENT;
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
			return (hospital->idDoctor(idSearch, input));	
			break;
		}
		cout << ">";
	}
	return nullptr;
}

void		uiADoctor(Hospital *hospital)
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
				cout << RED << "Sorry " << ENDC << e.what() << "\nIt appears you do NOT work here.\n Talk to admin if you believe there is a problem by typing ./healthcare admin request_to_work_here <your_name>" << endl;
				exit(101);
			}
		}
		cout << ">";
	}
	doctor->loop(hospital);
}

int main(int ac, char **av)
{
	ModeUI		input;
	Hospital	hospital;

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

	User *user = nullptr;
	if (input == PATIENT)
	{
		user = initUser();
		if (user)
		{
			hospital.addPatient(user);
			user->ui(&hospital, 1);
		}
	}
	else if (input == IDPATIENT)
	{
		user = initUser(av[1], &hospital);
		if (!user)
			return -1;
		user->ui(&hospital, 1);
	}
	else if (input == DOCTOR)
		uiADoctor(&hospital);
	else if (input == ADMIN)
	{
		if (ac == 2)
			hospital.loop();
		else if (ac >= 3)
		{
			const char *msg = "request_to_work_here";
			if (strcmp(*(++av), msg) == 0)
			{
				if (++av)
					cout << GREEN << *av << ENDC << " Thank you for your interest in working with us.\n";
			}
		}
	}

	return 1;
}
















