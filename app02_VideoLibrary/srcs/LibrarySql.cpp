#include "../incl/Library.hpp"

void	Library::getFilter()
{
	string	msg;
	string input;

	cout << BLUE;
	putLeft("SELECT * FROM Library WHERE [GENRE/NAME/SCORE/ID] [=/!=/>/<] [CONDITION]", msg, 32);
	cout << msg;
	cout << "|";

	while (getline(cin, input))
		break;
	cout << ENDC;
	runSql(input);
}

void	Library::runSql(string &cmd)
{
	vector<string> 	cmds;
	istringstream	ss(cmd);
	string			ptr;
	
	while (getline(ss, ptr, ' '))
		cmds.push_back(ptr);

	if (cmds.size() != 3)
	{
		cout << cmds.size() << endl;
		cout << RED << "Invalid:" << ENDC " SELECT * FROM Library WHERE " << cmd <<  endl;
		cout << "You need 3 arguments seperated by ' ' : Score > 5\n";
		this_thread::sleep_for(std::chrono::seconds(1));
		return ;
	}
	
	if (strCheck(cmds[0], "GENRE"))
		sqlOperation(GENRE, cmds);
	else if (strCheck(cmds[0], "NAME"))
		sqlOperation(NAME, cmds);
	else if (strCheck(cmds[0], "SCORE"))
		sqlOperation(SCORE, cmds);
	else if (strCheck(cmds[0], "ID"))
		sqlOperation(ID, cmds);
	else
	{
		cout << RED << "Invalid:" << ENDC " SELECT * FROM Library WHERE " << cmd <<  endl;
    	this_thread::sleep_for(std::chrono::seconds(1));
	}
}

// [=/!=/>/<]
void	Library::sqlOperation(SqlOp op, vector<string> &cmd)
{
	if (op == GENRE)
	{
		for (auto i : _games)
		{
			if (cmd[1] == "=")
			{
				if (!strCheck(i->strGenre(), cmd[2]))
					i->off();
			}
			if (cmd[1] == "!=")
			{
				if (strCheck(i->strGenre(), cmd[2]))
					i->off();
			}
			if (cmd[1] == ">")
			{
				if (strcasecmp(cmd[2].c_str(), i->strGenre().c_str()) > 0)
					i->off();
			}
			if (cmd[1] == "<")
			{
				if (strcasecmp(cmd[2].c_str(), i->strGenre().c_str()) < 0)
					i->off();
			}
		}
	}
	if (op == NAME)
	{
		for (auto i : _games)
		{
			if (cmd[1] == "=")
			{
				if (!strCheck(i->name(), cmd[2]))
					i->off();
			}
			if (cmd[1] == "!=")
			{
				if (strCheck(i->name(), cmd[2]))
					i->off();
			}
			if (cmd[1] == ">")
			{
				if (strcasecmp(cmd[2].c_str(), i->name().c_str()) > 0)
					i->off();
			}
			if (cmd[1] == "<")
			{
				if (strcasecmp(cmd[2].c_str(), i->name().c_str()) < 0)
					i->off();
			}
		}
	}
	if (op == SCORE)
	{
		for (auto i : _games)
		{
			if (cmd[1] == "=")
			{
				if (!strCheck(to_string(i->score()), cmd[2]))
					i->off();
			}
			if (cmd[1] == "!=")
			{
				if (strCheck(to_string(i->score()), cmd[2]))
					i->off();
			}
			if (cmd[1] == ">")
			{
				if (i->score() <= stoi(cmd[2]))
					i->off();
			}
			if (cmd[1] == "<")
			{
				if (i->score() >= stoi(cmd[2]))
					i->off();
			}
		}
	}
	if (op == ID)
	{
		vector<Game*>	tmp;
		copy_if(_games.begin(), _games.end(), back_inserter(tmp), [](Game* it) {
 		   return it->show();
		});
		try
		{
			int count = 1;
			if (cmd[1] == "=")
			{
				for (auto it : tmp)
				{
					if (stoi(cmd[2]) != count)
						it->off();
					count++;
				}
			}
			else if (cmd[1] == "!=")
			{
				for (auto it : tmp)
				{
					if (stoi(cmd[2]) == count)
						it->off();
					count++;
				}
			}
			else if (cmd[1] == ">")
			{
				for (auto it : tmp)
				{
					if (stoi(cmd[2]) >= count)
						it->off();
					count++;
				}
			}
			else if (cmd[1] == "<")
			{
				for (auto it : tmp)
				{
					if (stoi(cmd[2]) <= count)
						it->off();
					count++;
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
