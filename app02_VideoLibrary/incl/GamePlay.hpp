#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "../../Headers.hpp"

class GamePlay
{
	int		_score;
	string	_name;
public:
	GamePlay(string name, int score):_name(name), _score(score){};
	~GamePlay(){};

	void	uScore(int score){_score = score;};
	int		score(){return _score;};
};

#endif
