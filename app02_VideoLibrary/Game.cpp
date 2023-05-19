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

	rtn = _name + "," + genreToStr(_genre) + "," + to_string(get<0>(_topScore)) + "," + get<1>(_topScore);

	return rtn;
}

vector<tuple<int, string>> Game::strVector()
{
	vector<tuple<int,string>>	rtn;

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
			rtn.push_back(make_tuple(60,_name));
		if (i == 1)
			rtn.push_back(make_tuple(25,genreToStr(_genre)));
		if (i == 2 )
			rtn.push_back(make_tuple(10,to_string(get<0>(_topScore))));
		if (i == 3)
			rtn.push_back(make_tuple(25,get<1>(_topScore)));
	}

	return rtn;
}

