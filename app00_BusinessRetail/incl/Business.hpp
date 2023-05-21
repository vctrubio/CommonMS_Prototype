#ifndef BUSINESS_HPP
#define BUSINESS_HPP

#include "../../Headers.hpp"
#include "Utils.hpp"
#include "User.hpp"
#include "Product.hpp"
#include "Client.hpp"
#include "Transaction.hpp"


class User;
class Product;
class Transaction;

class Business
{
	static int										s_int;
	User											*_belongs_to;
	string											_name;
	int												_revenue;
	vector<Product*>								_products;
	vector<Client*>									_queue;
	vector<tuple<Product*,Client*, Transaction*>>	_invoice;
	vector<Client*>									_allClients;
public:
	Business(User *user, string name); 
	~Business();

	string					getName(){return _name;};
	int						stock();
	void					addProduct(Product *ptr){_products.push_back(ptr);};
	vector<Product*>		products(){return _products;};
	string					revenue(){return to_string(_revenue);};
	void					createProduct();
	void					addQueue(Client *client){_queue.push_back(client); _allClients.push_back(client);};
	vector<Client*>			queue(){return _queue;};
	void					popQueue(){_queue.erase(_queue.begin());};
	void					threading();
	void					addInvoice(Client *client);
	Product					*rtnRandomProduct();
	void					clearQueue(){_queue.clear();};
};

#endif
