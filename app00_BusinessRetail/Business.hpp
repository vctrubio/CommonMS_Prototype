#ifndef BUSINESS_HPP
#define BUSINESS_HPP

#include "../Headers.hpp"
#include "User.hpp"
#include "Product.hpp"


class User;
class Product;

class Business
{
	User				*_belongs_to;
	string				_name;
	int					_revenue;
	vector<Product*>	_products;
public:
	Business(User *user, string name); 
	~Business(){};

	void test();
	string	getName(){return _name;};
	void	addProduct(Product *ptr){_products.push_back(ptr);};
};

#endif
