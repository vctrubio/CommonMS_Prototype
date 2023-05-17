#include "parseCsv.hpp"

void	addtoCSV(int id, Doctor *d)
{
	ifstream	fileD("doctors.csv");
	vector<int>	tmp;

	if (fileD.is_open())
	{
		string line;
		while (getline(fileD, line))
		{
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
			{
				tmp.push_back(stoi(data));
				break;
			}
		}
		fileD.close();
	}
	for (auto i : tmp)
	{
		if (i == id)
			return ;
	}
	ofstream	fileWrite("doctors.csv", ios::app);
	bool		check = filesystem::exists("doctors.csv");
	if (fileWrite.is_open())
	{
		// if (check)
		// 	fileWrite << "ID,NAME,HOSPITALIZED,DELETED\n";
		fileWrite << d->rtnCsv();
		fileWrite.close();
	}

}

void	addtoCSV(int id, Patient *p)
{
	ifstream	fileP("patients.csv");
	vector<int>	tmp;

	if (fileP.is_open())
	{
		string line;
		while (getline(fileP, line))
		{
			stringstream	ss(line);
			string			data;
			while (getline(ss, data, ','))
			{
				tmp.push_back(stoi(data));
				break;
			}
		}
		fileP.close();
	}
	for (auto i : tmp)
	{
		if (i == id)
			return ;
	}

	ofstream	fileWrite("patients.csv", ios::app);
	bool		check = filesystem::exists("patients.csv");
	if (fileWrite.is_open())
	{
		// if (check)
		// 	fileWrite << "ID,NAME,HOSPITALIZED,DELETED\n";
		fileWrite << p->rtnCsv();
		fileWrite.close();
	}
}

bool	validateDoctor(vector<string> data)
{
	if (data.size() != 4)
		return false;
	for (auto c : data[0])
	{
		if (!isdigit(c))
			return false;
	}
	for (auto c : data[1])
	{
		if (!isascii(c))
			return false;
	}
	if (!isdigit(data[2][0])) //or not enum range
		return false;
	if (data[3] != "true" && data[3] != "false")
	    return false;
	return true;
}
