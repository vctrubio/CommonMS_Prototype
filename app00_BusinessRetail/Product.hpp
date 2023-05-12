#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "../Headers.hpp"
#include "Business.hpp"


class Business;

class Product
{
	static unsigned int s_counterId;

	Business		*_belongs_to;
	string			_name;
	unsigned int	_price;
	unsigned int	_id;
	unsigned int	_sold;
public:
	Product(Business *business, string name, unsigned int price):_belongs_to(business), _name(name), _price(price), _id(s_counterId++), _sold(0){ cout << GREEN << "New Product: " << _name << " €" << _price << " :=>" << _belongs_to << ENDC << endl;};
	~Product(){};

	void	print(){cout << "[" << _id << "] " << _name << " €" << _price << endl;};
	int		getPrice(){return _price;};
	string	getName(){return _name;};
	string	getBsn();
	string	getId(){return to_string(_id);};
	string	getSold(){return to_string(_sold);};
};

#endif
