#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "../../Headers.hpp"
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
	string			_userName;
	vector<Game*>	_games;
	Sort			_mode;
public:
	Library(){};
	~Library();

	void	loop();
	void	parse(string filename);
	void	addG(vector<string> &args);
	void	print(){for (auto g : _games) cout << g->inf() << endl;};
	void	printConsole(Sort flag);
	string	sortToStr(Sort mode);
	void	setUser(string name){_userName = name;};

	void	allFilter(){for (auto i : _games){i->on();};};
	void	getFilter();
	void	runSql(string &cmd);
	void	sqlOperation(SqlOp op, vector<string> &cmd);

	void	findId(string input);
	void	arcade();
	void	newGame();
	void	userAddGame(string name, int index){_games.push_back(new Game(name, iGenre(index)));};

	vector<Game*>	rGames(){vector<Game*> g; for (auto i : _games){
		if (i->show())
		 g.push_back(i)
		 ;} return g;};
};

Sort		getSort();
bool		isId(string input);
int 		strCheck(string s1, string s2);
int			strExist(string s1, string s2);
void		findId(string input);
string     	randDiff();
#endif
