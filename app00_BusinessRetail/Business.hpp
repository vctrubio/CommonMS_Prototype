#ifndef BUSINESS_HPP
#define BUSINESS_HPP

#include "../Headers.hpp"
#include "Utils.hpp"
#include "User.hpp"
#include "Product.hpp"
#include "Client.hpp"


class User;
class Product;

class Business
{
	User				*_belongs_to;
	string				_name;
	int					_revenue;
	vector<Product*>	_products;
	vector<Client*>		_queue;
public:
	Business(User *user, string name); 
	~Business(){};

	string				getName(){return _name;};
	void				addProduct(Product *ptr){_products.push_back(ptr);};
	vector<Product*>	products(){return _products;};
	string				revenue(){return to_string(_revenue);};
	void				createProduct();
	void				addQueue(Client *client){_queue.push_back(client);};
	vector<Client*>		queue(){return _queue;};
	void				threading();
	//needs to be a tuple of client, and product.
};

#endif
