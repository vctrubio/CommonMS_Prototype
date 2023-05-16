#ifndef UIMSG_HPP
#define UIMSG_HPP

#include "../Headers.hpp"

void	msgErrorArgumentCount()
{
	cout << "\nThis healthcare system needs an argument.\n";
	cout << "admin for administration purposes only.\n";
	cout << GREEN << "patient" << ENDC << " for logging new users, or please provide your id. ie: ./healthcare patient 21\n";
	cout << GREEN << "Doctor" << ENDC << " if you you're a doctor .........\n";
	cout << "Thank you and try again.\n\n";
};

#endif
