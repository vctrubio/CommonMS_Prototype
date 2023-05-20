#include "../incl/Library.hpp"

void    Library::loop()
{
    string  input;
	Sort	flag;

	system("clear");
	printConsole(flag);
	flag = _mode;
    cout << "|";
    while(getline(cin, input))
    {
        if (input == "/exit")
			break;
		if (input == "/help")
		{
			welcome();
			continue;
		}
		if (input == "/sort")
			flag = getSort();
		if (input == "/filter")
			getFilter();
		if (input == "/all")
			allFilter();
		if (isId(input))
			findId(input);
		if (input == "/arcade")
		{
			arcade();
		}
		system("clear");
		printConsole(flag);
        cout << "|";
		flag = _mode;
    }
};

void	Library::addG(vector<string> &args)
{
	if (args.empty())
		return ;
	try
	{
		string				paramOne;
		Genre				paramTwo;
		tuple<int, string>	paramThree;
		
		if (!args[0].empty())
			paramOne = args[0];
		else
			throw runtime_error("Adding to Games.\n");
		if (!args[1].empty())
			paramTwo = strToGenre(args[1]);
		else
			paramTwo = OTHER;
		if (!args[2].empty() && !args[3].empty())
		{
			get<0>(paramThree) = stoi(args[2]);
			get<1>(paramThree) = args[3];
		}
		else
		{
			get<0>(paramThree) = 0;
			get<1>(paramThree) = "0";
		}
		_games.push_back(new Game(paramOne, paramTwo, paramThree));
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;	
	}
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
        		return game1->name() > game2->name();});
		}
		if (flag == DN)
		{
			sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        		return game1->name() < game2->name();});
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
