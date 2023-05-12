#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "../Headers.hpp"
#include "Business.hpp"
#include "Product.hpp"
#include "Client.hpp"

//param- business, product, client
class Business;
class Product;
class Client;

class Transaction
{
	Business	*_belongs_to;
	Product		*_product;
	Client		*_client;
	string		_log;
	time_t		_date;
public:
	Transaction(Business *bsn, Product *product, Client *client);
	~Transaction(){};
};

#endif
