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

	if (prd->archive())
		cout << RED << "DELETED/REMOVED from Stock\n" << ENDC;

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

void	testing(Business *bsn)
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

cout << "People are lining up...\n";
for (int i = 0; i < 5; i++)
{
	bsn->addQueue(new Client("Stranger" +to_string(i)));
	this_thread::sleep_for(chrono::seconds(1));
}
cout << "Check you queue(;";
}


void	uiQueue(Business *bsn)
{
	string input;

	clear();
	cout << GREEN << bsn->getName() << ENDC << endl;
	cout << "Queue size: " << bsn->queue().size() << endl;
	cout << "Type 'checkout' to check everyone out\n";
	cin >> input;
	if (input == "checkout")
	{
		for (auto i : bsn->queue())
			cout << "checkouting.\n";
	}
}

void	uiBsn(Business *bsn)
{
	string input;

	clear();
	cout << "Welcome to " << GREEN << bsn->getName() << ENDC << " STOCK [" << bsn->products().size() << "]" << " TOTAL REVENUE = €" << bsn->revenue() << endl;
	if (bsn->products().empty())
		cout << RED << "No Products to show, type 'new' to create one" << ENDC << endl;
	else
	{
		for (auto i : bsn->products())
		{
			if (!i->archive())
				i->print();
		}
	}

	cin >> input;
	if (input == "0" || input == "exit")
		return ;
	else if (input == "new")
	{
		bsn->createProduct();
		return ;
	}
	else if (input == "open")
	{
        std::thread threadObj(&Business::threading, bsn); // Create a thread for bsn->threading()
		threadObj.detach(); // Detach the thread and allow it to run independently
		for (int i = 0; i < 10; i++)
		{
			cout << bsn->queue().size() << "........\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		/*
		Please note that detaching a thread means that you are no longer synchronizing it with the main thread. The detached thread will continue to run even if the main thread exits. Also, make sure to handle any synchronization or thread safety concerns when accessing shared data structures like the bsn->queue() in the bsn->threading() function.
		*/
	}
	else if (input == "queue")
	{
		cout << "Displaying Queue... " << bsn->queue().size() << endl;
		this_thread::sleep_for(chrono::seconds(1));

	}
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
