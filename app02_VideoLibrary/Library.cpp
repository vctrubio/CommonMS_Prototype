#include "Library.hpp"

void    Library::loop()
{
    string  input;
	Sort	flag;

	system("clear");
	printConsole(flag);
	flag = _mode;
    cout << "|";
    while(_on && getline(cin, input))
    {
        if (input == "/exit")
		{
            _on = false;
			break;
		}
		if (input == "/help")
		{
			welcome();
			continue;
		}
		if (input == "/sort")
			flag = getSort();
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

void	Library::print()
{

	for (auto g : _games)
		cout << g->inf() << endl;
}

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
		// sort(_games.begin(), _games.end(), [](Game* game1, Game* game2) {
        // 	return game1->score() > game2->score();});
	}
	for (auto game : _games)
		box(game->strVector());
}



///VALIDATION INITSs///////////////////////////////
static bool	validateHeader(string line)
{
	int 	count = 0;
	string	tmp;

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ',')
			count++;
	}
	if (count != 3)
		return false;
	count = 1;
	istringstream ss(line);
	while(getline(ss, tmp, ','))
	{
		if (count == 1 && tmp != "Name")
			return false;
		if (count == 2 && tmp != "Category")
			return false;
		if (count == 3 && tmp != "Top Score")
			return false;
		if (count == 4 && tmp != "User")
			return false;
		count++;
	}
	return true;

}

static bool	ftvalidate(ifstream &file, vector<string> &cpy)
{
	string 	line;
	bool	firstline = true;

	while (getline(file, line))
	{
		if (firstline)
		{
			firstline = false;
			if (validateHeader(line))
				continue;
			cout << RED << "Error in CSV Headers." << ENDC << endl;
			return false;
		}
		cpy.push_back(line);
	}
	return true;
}

void	Library::parse(string filename)
{
	ifstream		file(filename);
	vector<string>	line;

	if (file.is_open())
	{
		if (ftvalidate(file, line))
		{
			for (auto it : line)
			{
				vector<string> tmp;
				stringstream	ss(it);
				string			data;
				while (getline(ss, data, ','))
					tmp.push_back(data);
				addG(tmp);
			}
		}
	}
	else
		cout << RED << "Error in parsing CSV2." << ENDC << endl;
	file.close();
}



//////////////////Circular depenciens............. Should be in UI.
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