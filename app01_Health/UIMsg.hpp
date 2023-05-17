#ifndef UIMSG_HPP
#define UIMSG_HPP

#include "../Headers.hpp"
#include "Patient.hpp"
#include "Doctor.hpp"

class Patient;
class Doctor;

void	msgErrorArgumentCount()
{
	cout << "\nThis healthcare system needs an argument.\n";
	cout << GREEN << "'admin'" << ENDC << " for administration purposes only.\n";
	cout << GREEN << "'patient'" << ENDC << " for logging new users, or please provide your id. ie: ./healthcare patient 21\n";
	cout << GREEN << "'doctor'" << ENDC << " if you you're a doctor .........\n";
	cout << "Thank you and try again.\n\n";
};


void	uiPatient(Patient *p)
{
	string alta = p->ingr()? "alta" : "baja";
	
	cout << "-----------------------------\n";
	cout << "| " << p->id() << " | " << p->name() << " | ";
	cout << alta << " | History [" << p->appointments.size() << "] \n";
	cout << " - - - - - - - - - - - - - - \n";
	cout << "|'new' for a new appointment|\n";
	cout << "|'chat' to talk to a doctor |\n";
	cout << "|'exit' to leave            |\n";
	cout << "----------------------------\n";


	if (p->ingr())
	{
		cout << ":Currently in Room X\n";
	}
}

void	uiDoctor(Doctor *d)
{
	cout << "-------------------------------\n";
	cout << "| Welcome Dct. " << d->name() << "         |\n";
	cout << "| You have X pending request |\n";
	cout << "------------------------------\n";


}


#endif
