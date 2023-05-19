#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "../Headers.hpp"
#include "Ui.hpp"

class Library
{
	bool	_on;

public:
	Library():_on(true){};
	~Library(){};

	bool	online(){return _on;};
	void	exit(){_on = false;};
	void	loop();
	
};





#endif
