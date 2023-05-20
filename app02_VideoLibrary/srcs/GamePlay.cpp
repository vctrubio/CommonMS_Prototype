#include "../incl/GamePlay.hpp"
#include "../incl/Game.hpp"

void    Game::addGame(string username, int score)
{
    GamePlay    *g = new GamePlay(username, score);
    if (score > get<0>(_topScore))
    {
        get<0>(_topScore) = score;
        get<1>(_topScore) = username;
    }
    _play.push_back(g);
}