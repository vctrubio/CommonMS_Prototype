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
	displayBarProduct();
	cout << GREEN << prd->getName() << ENDC << " €" << to_string(prd->getPrice()) << endl;
	cout << "Total Sales[" << prd->trans().size() << "]\n";
	cout << "Total Revenue " << prd->getSold() << endl;

	if (prd->archive())
		cout << RED << "DELETED/REMOVED from Stock\n" << ENDC;
debugger

	if (prd->trans().size() > 0)
		cout << "--------------------TRANSACTIONS-------------------\n";
	for (auto i : prd->trans())
		cout << i;
	if (prd->trans().size() > 0)
		cout << "---------------------------------------------------\n";

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

	displayBarQueue();
	if (flag == 1)
		cout << "|-----------CHECKED-OUT√-----------|\n";
	if (flag == 2)
		cout << "|-----------CLOSED-XXX-------------|\n";
	cout << GREEN << bsn->getName() << ENDC << endl;
	cout << "Queue size: " << bsn->queue().size() << endl;

	for (auto i : bsn->queue())
	{
		cout << count++ << ": " << i->getName() << endl;
		for (auto j : i->products())
			cout << "\t:" << j->getName() << endl;	
	}

	cout << endl;	
	cout << ">";
	cin >> input;
	if (input == "checkout")
	{
		clear();
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
	else if (input == "close")
	{
		bsn->clearQueue();
	    uiQueue(bsn, 2);
        return ;
	}
	uiQueue(bsn, 0);
}

void	uiBsn(Business *bsn, int flag)
{
	string input;

	clear();
	if (!flag)
		displayBarBsn();
	else 
		displayBarBsnHelp();

	cout << "Welcome to " << GREEN << bsn->getName() << ENDC << " STOCK [" << bsn->products().size() << "]" << " TOTAL REVENUE = €" << bsn->revenue() << endl;
	cout << YELLOW << "Your Queue is: " << bsn->queue().size() << ENDC << endl;

	for (auto i : bsn->products())
	{
		if (i->archive())
			cout << RED; 
		i->print();
		cout << ENDC;
	}

	cout << endl;
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
		bsn->createProduct();
	else if (input == "open")
	{
		std::unique_lock<std::mutex> lock(mtx);
		std::thread threadObj(&Business::threading, bsn);
		cv.wait(lock, [] { return threadSignal; });
		threadObj.join();
		threadSignal = false;
	}
	else if (input == "queue")
	{
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
	uiBsn(bsn, 0);
}
