#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../Headers.hpp"

class Client
{
	string 	_name;
	int		_cash; //for now, idea to create a wallet class.
public:
	Client(string name):_name(name), _cash(999){};
	~Client(){};

	string	getName(){return _name;};
	int		getCash(){return _cash;};
};

#endif
