#ifndef USER_HPP
#define USER_HPP

#include "../Headers.hpp"
#include "Business.hpp"

class Business;

class User
{
	static unsigned int s_counterId;

	string				_name;
	unsigned int		_id;

	Business*			_bsn;
public:
	User(string name):_name(name), _id(s_counterId++), _bsn(nullptr){};
	~User(){};

	string		getName(){return _name;};
	string		getBsn();
	void		updateBsn(Business *bsn);
};

#endif
