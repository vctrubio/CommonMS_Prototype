#include "Business.hpp"
#include "Product.hpp"
#include "Client.hpp"
#include "Transaction.hpp"
#include "User.hpp"
#include "UIBar.hpp"

void	uiBsn(Business *bsn, int flag);

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

	cout << endl;
	displayBarProduct();
	cout << endl;
	
	while (42)
	{
		cout << ">";
		cin >> input;
		if (input == "0" || input == "exit")
			break ;
		else if (input == "back")
		{
			uiBsn(prd->bsn(), 0);
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
		displayBarProductHelp();
	}
}

void	uiQueue(Business *bsn, int flag)
{
	string 	input;
	int		count = 1;

	if (!flag)
		clear();
	else
		cout << "-----------CHECKOUT√----------------\n";
	cout << GREEN << bsn->getName() << ENDC << endl;
	cout << "Queue size: " << bsn->queue().size() << endl;
	displayBarQueue();

	for (auto i : bsn->queue())
	{
		cout << count++ << ": " << i->getName() << endl;
		for (auto j : i->products())
			cout << "\t:" << j->getName() << endl;	
	}
	cout << ">";
	cin >> input;
	if (input == "checkout")
	{
		for (auto i : bsn->queue())
		{
			bsn->addInvoice(bsn->queue().front());
			bsn->popQueue();
		}
		uiQueue(bsn, 1);
		return ;
	}
	else if (input == "back" || input == "home")
	{
		uiBsn(bsn, 0);
		return ;
	}
	uiQueue(bsn, 1);
}

void	uiBsn(Business *bsn, int flag)
{
	string input;

	clear();

	cout << "Welcome to " << GREEN << bsn->getName() << ENDC << " STOCK [" << bsn->products().size() << "]" << " TOTAL REVENUE = €" << bsn->revenue() << endl;
	
	cout << YELLOW << "Your Queue is: " << bsn->queue().size() << ENDC << endl;

	if (!flag)
		displayBarBsn();
	else 
		displayBarBsnHelp();

	for (auto i : bsn->products())
	{
		if (i->archive())
			cout << RED; 
		i->print();
		cout << ENDC;
	}
	
	cout << ">";
	cin >> input;
	if (input == "help")
	{
		displayBarBsnHelp();
		uiBsn(bsn, 1);
	}
	if (input == "0" || input == "exit")
		return ;
	else if (input == "new")
	{
		bsn->createProduct();
	}
	else if (input == "open")
	{
		std::unique_lock<std::mutex> lock(mtx);
		std::thread threadObj(&Business::threading, bsn); // Create a thread for bsn->threading()
		cv.wait(lock, [] { return threadSignal; });
		threadObj.join();
		threadSignal = false;
	}
	else if (input == "queue")
	{
		cout << "Displaying Queue... Size .... " << bsn->queue().size() << endl;
		this_thread::sleep_for(chrono::seconds(1));
		uiQueue(bsn, 0);
		return ;
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
	cout << "FININISHED.\n";
	uiBsn(bsn, 0);
}
