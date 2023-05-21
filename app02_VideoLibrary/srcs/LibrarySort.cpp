#include "../incl/Library.hpp"

string	Library::sortToStr(Sort mode)
{
	if (mode == AN)
		return "Ascending Title";
	if (mode == DN)
		return "Descending Title";
	if (mode == AS)
		return "Ascending Top Score";
	if (mode == DS)
		return "Descending Top Score";
	if (mode == GG)
		return "Ascending Genres";
	return "Common Managment Solutions";
}

Sort		getSort()
{
	string	input;
	string	output;

	putLine(output, '-');
	putLeft("|OPTIONS| 'AN' 'DN' on Name | 'AS' 'DS' on Score | 'GG' on Genre", output, 32);
	putLine(output, '-');
	cout << output << "|";

	while(getline(cin, input))
    {
        if (input == "/back")
			break;
		if (input == "AN")
			return AN;
		if (input == "DN")
			return DN;
		if (input == "AS")
			return AS;
		if (input == "DS")
			return DS;
		if (input == "GG")
			return GG;
		cout << "|";
    }
	return NM;
}

void	Library::printConsole(Sort flag)
{
	string buffer;

	buffer += YELLOW;	
	putLeft(sortToStr(flag), buffer, 32);
	buffer += ENDC;
	putLine(buffer, '-');
	cout << buffer;

	if (flag != _mode)
	{
		if (flag == AN)
		{
			sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        		return game1->name() < game2->name();});
		}
		if (flag == DN)
		{
			sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        		return game1->name() > game2->name();});
		}
		if (flag == AS)
		{
			sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        		return game1->score() > game2->score();});
		}
		if (flag == DS)
		{
			sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        		return game1->score() < game2->score();});
		}
		if (flag == GG)
		{
			sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        		return game1->strGenre() < game2->strGenre();});
		}
	}
	int count = 1;
	for (auto game : _games)
	{
		if (game->show())
			box(game->strVector(), count);
	}
}