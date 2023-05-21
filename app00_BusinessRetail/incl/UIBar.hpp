#include "Business.hpp"

void    displayBarQueue()
{
    cout << " ------------------------------" << endl;
    cout << "| home/back | checkout | close |" << endl;
    cout << " ------------------------------" << endl;
}

void    displayBarBsnHelp()
{
	cout << " -----------------------------------" << endl;
	cout << " Different Commands--" << endl;
	cout << "-ID# '1' to jump into product ID#1\n";
	cout << "-open to open to the public!\n";
	cout << "-new to add a new product \n";
	cout << "-0 or exit to stop and save \n";
	cout << " -----------------------------------" << endl;
}

void    displayBarBsn()
{
    cout << " ------------------------------------" << endl;
    cout << "| ID# | open | queue | new | 0/exit |" << endl;
    cout << " ------------------------------------" << endl;
}

void	displayBarProductHelp()
{
	cout << " -----------------------------------" << endl;
	cout << " Different Commands--" << endl;
	cout << "-uname for updating name\n";
	cout << "-uprice for updating price\n";
	cout << "-uprice for updating price\n";
	cout << "-back to go back to Business Page\n";
	cout << " -----------------------------------" << endl;
}

void    displayBarProduct()
{
    cout << " --------------------------------------- " << endl;
    cout << "| archive | uname | uprice | help | back|" << endl;
    cout << " --------------------------------------- " << endl;
}

void	clear()
{
    #ifdef _WIN32
    	std::system("cls");
    #else
    	std::system("clear");
    #endif
}