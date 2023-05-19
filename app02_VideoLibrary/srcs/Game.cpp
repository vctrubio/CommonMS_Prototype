#include "../incl/Game.hpp"

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
			rtn.push_back(make_tuple(70,_name));
		if (i == 1)
			rtn.push_back(make_tuple(20,genreToStr(_genre)));
		if (i == 2 )
			rtn.push_back(make_tuple(5,to_string(get<0>(_topScore))));
		if (i == 3)
			rtn.push_back(make_tuple(25,get<1>(_topScore)));
	}
	return rtn;
}

int		Game::showGame()
{
	cout << GREEN << name() << ENDC;
	string msg = " 'delete' 'update'\n";
	string input;

	cout << msg;
	while(getline(cin, input))
	{
		if (input == "back")
			return 1;
		if (input == "delete")
			return 0;
		if (input == "update")
		{
			string	in;
			cout << "'name' 'genre' 'both' \n";
			while(getline(cin, in))
			{
				if (in == "name" || in == "both")
				{
					string	name;
					cout << "New Name> ";
					while(getline(cin, name))
					{
						if (name.length() > 0)
						{
							cName(name);
							if (name == "name")
								return 1;
							break;
						}
					}
				}
				if (in == "genre" || in == "both")
				{
					string	genre;
					cout << "New Genre. Pick by index.\n";
					cout << "[1] Educational\n[2] Violent\n[3] Mysterious\n[4] Other\n:";
					while(getline(cin, genre))
					{
						if (genre.length() > 0)
							cGenre(genre[0] - 48);
						return 1;
					}
				}
				return 1;
			}
		}
		break;
	}
	return 1;
}

void	Game::cGenre(int i)
{
	cout << "i is " << i << endl;
	if (i == 1)
		_genre = EDUCATIONAL;
	if (i == 2)
		_genre = VIOLENT;
	if (i == 3)
		_genre = MYSTERIOUS;
	if (i == 4)
		_genre = OTHER;
}