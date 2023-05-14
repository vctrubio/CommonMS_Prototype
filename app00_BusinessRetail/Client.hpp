#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "../Headers.hpp"
#include "Product.hpp"

class Product;

class Client
{
	string 				_name;
	int					_cash; //for now, idea to create a wallet class.
	vector<Product*>	_cart;
public:
	Client(string name):_name(name), _cash(999){};
	~Client(){cout << RED << _name << ENDC << " :Deconstructed -- for_debug_purposes\n";}; //fdp

	string				getName(){return _name;};
	int					getPrice(){return _cash;};
	void				subtract(int ammount){_cash -= ammount;};
	void				addToCart(Product *prd){_cart.push_back(prd);};
	Product 			*getProduct();
	vector<Product*>	products(){return _cart;};
};

#endif
