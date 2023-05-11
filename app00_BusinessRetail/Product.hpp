#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "../Headers.hpp"
#include "Business.hpp"


class Business;

class Product
{
	Business		*_belongs_to;
	string			_name;
	unsigned int	_price;
public:
	Product(Business *business, string name, unsigned int price):_belongs_to(business), _name(name), _price(price){};
	~Product(){};
};

#endif
