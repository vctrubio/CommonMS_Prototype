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

	if (prd->trans().size() > 0)
		cout << "--------------------TRANSACTIONS-------------------\n";
	for (auto i : prd->trans())
		cout << i;
	if (prd->trans().size() > 0)
		cout << "---------------------------------------------------\n";

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
		else if (input == "archive")
		{
			prd->toggleArchive();
			uiProduct(prd);
			return ;
		}
		cout << "Sorry no cmds found.\n0/exit\nback\nuprice to update the price\nuname to update the name\narchive to remove it from stock || archive to re-stock it\n";
	}
}

void	uiQueue(Business *bsn)
{
	string 	input;
	int		count = 1;
	clear();
	cout << GREEN << bsn->getName() << ENDC << endl;
	cout << "Queue size: " << bsn->queue().size() << endl;
	cout << "Type 'checkout' to check everyone out\n";
	
	for (auto i : bsn->queue())
	{
		cout << count++ << ": " << i->getName() << endl;
		for (auto j : i->products())
			cout << "\t:" << j->getName() << endl;	
	}

	cin >> input;
	if (input == "checkout")
	{
		for (auto i : bsn->queue())
		{
			bsn->addInvoice(bsn->queue().front());
			bsn->popQueue();
		}
	}
	else
		cout << "Sorry cmd not found, returning to HOME\n";
	uiBsn(bsn);
}

void	uiBsn(Business *bsn)
{
	string input;

	clear();
	cout << "Welcome to " << GREEN << bsn->getName() << ENDC << " STOCK [" << bsn->products().size() << "]" << " TOTAL REVENUE = €" << bsn->revenue() << endl;
	
	//if open/closed
	cout << YELLOW << "Your Queue is: " << bsn->queue().size() << ENDC << endl;


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
		cout << "GOT THIS FAR NOWW WHART\n";
	}
	else if (input == "queue")
	{
		cout << "Displaying Queue... " << bsn->queue().size() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		uiQueue(bsn);
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
