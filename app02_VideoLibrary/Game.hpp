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

string	genreToStr(Genre gen);
Genre	strToGenre(string str);

class Game
{
	bool				_show = true;
	string				_name;
	tuple<int,string>	_topScore;
	list<GamePlay*>		_games;
	Genre				_genre;
public:
	Game(string name):_name(name){_genre = OTHER;};
	Game(string name, Genre gen):_name(name),_genre(gen){};
	Game(string name, Genre gen, tuple<int,string> t):_name(name),_genre(gen),_topScore(t){};
	~Game(){};

	void						addGame(GamePlay *g){_games.push_back(g);}; //& not ptr..
	bool						show(){return _show;};
	void						off(){_show = false;};
	void						on(){_show = true;};

	string						name(){return _name;};
	// Genre						genre(){return _genre;};
	string						strGenre(){return genreToStr(_genre);};
	int							score(){return get<0>(_topScore);};
	


	string						inf();
	vector<tuple<int,string>>	strVector();
};



#endif
