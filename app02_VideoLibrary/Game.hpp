#ifndef GAME_HPP
#define GAME_HPP

#include "../Headers.hpp"
#include "GamePlay.hpp"
#include "User.hpp"

class GamePlay;
class User;

enum Genre
{
	EDUCATIONAL = 1,
	VIOLENT = 2,
	MYSTERIOUS = 3,
	OTHER = 4
};

class Game
{
	string				_name;
	tuple<int,string>	_topScore;
	list<GamePlay*>		_games;
	Genre				_genre;
public:
	Game(string name):_name(name){_genre = OTHER;};
	Game(string name, Genre gen):_name(name),_genre(gen){};
	~Game(){};

	void	addGame(GamePlay *g){_games.push_back(g);};
	string	inf();
};

Genre	strToGenre(string str);
bool	validateHeader(string line);
bool	validate(ifstream file);

#endif
