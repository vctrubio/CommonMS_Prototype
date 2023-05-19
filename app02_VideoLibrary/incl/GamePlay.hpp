#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "../../Headers.hpp"
#include "User.hpp"

class User;

class GamePlay
{
	int		_score;
	User*	_user;
public:
	GamePlay(User *u):_user(u),_score(0){};
	~GamePlay(){};

	void	uScore(int score){_score = score;};
	int		score(){return _score;};
};

#endif
