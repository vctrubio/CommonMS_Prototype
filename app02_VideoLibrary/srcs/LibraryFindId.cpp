#include "../incl/Library.hpp"

bool	isId(string input)
{
	if (input[0] == '/')
	{
		for (int i = 1; i < input.length(); i++)
		{
			if (input[i] < '0' || input[i] > '9')
				return false;
		}
		if (input[1])
			return true;
	}
	return false;
}

int strCheck(string s1, string s2) {
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	if(s1.compare(s2) == 0)
    	return 1;
	return 0;
}

void	Library::findId(string input)
{
	int	id = stoi(input.substr(1));
	if (id == 0)
		return ;

	int count = 1;

	for (auto i : rGames())
	{
		if (count == id)
		{
        	if (i->showGame())
			{
				iter_swap(&i, _games.end() - 1);
				Game	*ptr = _games.back();
				_games.pop_back();
				delete ptr;
				break;
			}
		}
		count++;
	}
}