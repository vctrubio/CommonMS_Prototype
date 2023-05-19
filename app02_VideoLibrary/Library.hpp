#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "../Headers.hpp"
#include "Ui.hpp"
#include "Game.hpp"

class Game;

enum Sort
{
	NM, //Normal
	AN, //ASC NAME
	DN,
	AS,	//ASC SCORE
	DS,
	GG	//GENRE
};

enum SqlOp
{
	GENRE,
	NAME,
	SCORE,
	ID
};

class Library
{
	bool														_on;
	vector<Game*>												_games;
	vector<array<variant<string, Genre, tuple<int,string>>, 3>>	_filtered;
	Sort														_mode;
public:
	Library():_on(true){};
	~Library(){};

	bool	online(){return _on;};
	void	exit(){_on = false;};
	void	loop();
	void	parse(string filename);
	void	addG(vector<string> &args);
	void	print();
	void	printConsole(Sort flag);
	string	sortToStr(Sort mode);

	void	getFilter();
	void	runSql(string &cmd);
	void	sqlOperation(SqlOp op, vector<string> &cmd);
};

Sort		getSort();



#endif
