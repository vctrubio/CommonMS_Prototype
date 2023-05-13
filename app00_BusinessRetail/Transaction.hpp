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
	static unsigned int s_counterId;

	unsigned int	_id;
	Business		*_belongs_to;
	Product			*_product;
	Client			*_client;
	string			_log;
	string			_date;
public:
	Transaction(Business *bsn, Product *product, Client *client);
	~Transaction(){};

	string	getName(){return _log;};
};
//memory leaks, need to keep note somewhere
#endif
