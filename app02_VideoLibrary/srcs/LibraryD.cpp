#include "../incl/Library.hpp"

Library::~Library()
{
    //parse CSV
    //delete memory
        //games,gameplay

	const char  *csvFile = "data.csv";
	ofstream fileWrite(csvFile);
	if (fileWrite.is_open())
	{
		fileWrite << "Name,Category,Top Score,User\n";
        for (auto i : _games)
        {
            fileWrite << i->inf();
            delete i;
        }

		fileWrite.close();
	}
    
}