#include "Business.hpp"
#include "Product.hpp"
#include "Client.hpp"
#include "Transaction.hpp"
#include "User.hpp"

void	uiBsn(Business *bsn);

void	clear()
{
	#ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

void	uiProduct(Product *prd)
{
	string input;

	clear();
	cout << GREEN << prd->getName() << ENDC << " €" << to_string(prd->getPrice()) << endl;
	cout << "Total Sales[" << prd->trans().size() << "]\n";
	cout << "Total Revenue " << prd->getSold() << endl;

	for (auto i : prd->trans())
		cout << i;
	
	while (42)
	{
		cout << ">";
		cin >> input;
		if (input == "0" || input == "exit")
			return ;
		else if (input == "back")
		{
			uiBsn(prd->bsn());
			return ;
		}
		else if (input == "uname")
		{
			cout << "Enter new name of product\n>";
			cin >> input;
			prd->updateName(input);
			uiProduct(prd);
			return ;
		}
		else if (input == "uprice")
		{
			cout << "Enter new name of product\n>";
			cin >> input;
			prd->updatePrice(stoi(input));
			uiProduct(prd);
			return ;
		}
		cout << "Sorry no cmds found.\n0/exit\nback\nuprice to update the price\nuname to update the name\n";
	}
}

void	thread_open(Business *bsn)
{
//create a thread
//+create a pipe;
//that creates a queue, 
//that finds a client and adds it to the quee to request to buy a product.
//
//post message of 'Client: Maria wants to purchase X' 'Press 1 to accept'
//
//
//
//close to close.
//back to go back.
//exit to exit 
}

void	uiBsn(Business *bsn)
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

	cin >> input;
	if (input == "0" || input == "exit")
		return ;
	else if (input == "new")
		bsn->createProduct();
	else if (input == "open")
		thread_open(bsn);
	else
	{
		for (auto i : bsn->products())
		{
			if (input == i->getId())
			{
				uiProduct(i);
				return ;
			}
		}
	}
	uiBsn(bsn);
}
