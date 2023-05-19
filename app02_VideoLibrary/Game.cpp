#include "Game.hpp"

Genre	strToGenre(string str)
{
	if (str == "EDUCATIONAL")
		return EDUCATIONAL;
	if (str == "VIOLENT")
		return VIOLENT;
	if (str == "MYSTERIOUS")
		return MYSTERIOUS;
	return OTHER;
}

string	genreToStr(Genre gen)
{
	if (gen == EDUCATIONAL)
		return "EDUCATIONAL";
	if (gen == VIOLENT)
		return "VIOLENT";
	if (gen == MYSTERIOUS)
		return "MYSTERIOUS";
	return "OTHER";
}

string	Game::inf()
{
	string	rtn;

	rtn = _name;
	rtn += genreToStr(_genre); 

	return rtn;
}

