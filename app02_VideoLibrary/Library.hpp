#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "../Headers.hpp"
#include "Ui.hpp"
#include "Game.hpp"

class Game;

class Library
{
	bool			_on;
	vector<Game*>	_games;
public:
	Library():_on(true){};
	~Library(){};

	bool	online(){return _on;};
	void	exit(){_on = false;};
	void	loop();
	void	parse(string filename);
	void	addG(vector<string> &args);
	void	print();
	void	printConsole();
};





#endif
