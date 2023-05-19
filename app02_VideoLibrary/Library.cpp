#include "Library.hpp"

void    Library::loop()
{
    string  input;

    system("clear");
    cout << "|";
    while(_on && getline(cin, input))
    {
		print();
        cout << "|";
        if (input == "/exit")
            _on = false;
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
	cout << "TRUEEEEE.\n";
	return true;

}

bool	ftvalidate(ifstream &file)
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
	}
	return true;
}

void	Library::parse(string filename)
{
	ifstream	file(filename);

	if (file.is_open())
	{
		if (ftvalidate(file))
		{
			string line;

			bool	firstLine = true;
			while (getline(file, line))
			{
				if (firstLine)
				{
					firstLine = false;
					continue;
				}
				vector<string>	tmp;
				stringstream	ss(line);
				string			data;
				while (getline(ss, data, ','))
					tmp.push_back(data);
				addG(tmp);
			}
		}
		else
			cout << RED << "Error in parsing CSV2." << ENDC << endl;
		file.close();
	}
	else
		cout << RED << "Error in parsing CSV1." << ENDC << endl;
}

void	Library::addG(vector<string> &args)
{
	if (args.empty())
		return ;
	//if (args.size() == 1)
		_games.push_back(new Game(args.front()));		
	cout << "SIZE of VECT. " << args.size() << endl;
	/*
	if (args.size() == 2)
		_games.push_back(new Game(args[0], strToGenre(args[1])));
	if (args.size() == 4)
		_games.push_back(new Game(args[0], strToGenre(args[1]), tuple<int,string> tmp(stoi ));
		  //; //we have a top score info
*/
}

void	Library::print()
{
	for (auto g : _games)
		cout << g->inf() << endl;
}


void	Library::printConsole()
{

}
