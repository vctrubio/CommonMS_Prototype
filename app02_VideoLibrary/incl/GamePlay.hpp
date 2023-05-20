#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "../../Headers.hpp"

// class User;

class GamePlay
{
	int		_score;
	// User*	_user;
public:
	GamePlay():_score(0){};
	~GamePlay(){};

	void	uScore(int score){_score = score;};
	int		score(){return _score;};
};

#endif
