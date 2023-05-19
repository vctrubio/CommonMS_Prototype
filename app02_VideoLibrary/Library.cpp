#include "Library.hpp"

void    Library::loop()
{
    string  input;

	system("clear");
	printConsole();
    cout << ".|";
    while(_on && getline(cin, input))
    {
		printConsole();
        if (input == "/exit")
		{
            _on = false;
			break;
		}
        cout << "|";
    }
};

bool	validateHeader(string line)
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

bool	ftvalidate(ifstream &file, vector<string> &cpy)
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

void	Library::addG(vector<string> &args)
{
	//cout << "SIZE of VECT. " << args.size() << endl;
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


void	Library::printConsole()
{
	string buffer;

	buffer += YELLOW;
	putLeft("All Games", buffer, 32);
	buffer += ENDC;
	putLine(buffer, '-');

	cout << buffer;
	
	for (auto game : _games)
		box(game->strVector());

}
