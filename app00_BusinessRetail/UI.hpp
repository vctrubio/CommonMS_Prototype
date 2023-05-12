#include "Business.hpp"
#include "Product.hpp"
#include "Client.hpp"
#include "Transaction.hpp"
#include "User.hpp"

void	clear()
{
	#ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void	uiProduct(Business *bsn)
{
	string input;

	clear();
	cout << "Welcoming to " << GREEN << bsn->getName() << ENDC << " STOCK [" << bsn->products().size() << "]" << " TOTAL REVENUE = €" << bsn->revenue() << endl;
	if (bsn->products().empty())
		cout << RED << "No Products to show, type 'new' to create one" << ENDC << endl;
	else
	{
		for (auto i : bsn->products())
			i->print();
	}
	cout << BLUE << "----------\n---Type---\n" << ENDC << "ID# to see specific product\n'new' to add product\n" << BLUE << "----------\n" << ENDC;

	cin >> input;
	if (input == "0" || input == "exit")
		return ;
	//if input == id of product for into product name: 
	else if (input == "new")
		bsn->createProduct();
	else
	{
		for (auto i : bsn->products())
		{
			if (input == i->getId())
			{
				cout << "FOUND --- " << input << "\n";
			}
		}
	}
	uiProduct(bsn);
}
