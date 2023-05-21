#include "../incl/Library.hpp"

void    Library::loop()
{
    string  input;
	Sort	flag;

	system("clear");
	flag = _mode;
	printConsole(flag);
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
			arcade();
		if (input == "/new")
			newGame();
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

