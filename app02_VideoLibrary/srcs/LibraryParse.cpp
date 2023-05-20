#include "../incl/Library.hpp"

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
	{
		cout << RED << "Error in parsing CSV:" << ENDC << " Loading Empty Data: " << filename <<  endl;
		this_thread::sleep_for(chrono::seconds(2));
	}
	file.close();
}
