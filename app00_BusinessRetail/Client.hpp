#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../Headers.hpp"

class Client
{
	string _name;
public:
	Client(string name):_name(name){};
	~Client(){};

	string	getName(){return _name;};
};

#endif
