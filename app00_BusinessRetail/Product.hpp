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
	vector<string>	_transactions;
	bool			_archive;
public:
	Product(Business *business, string name, unsigned int price):_belongs_to(business), _name(name), _price(price), _id(s_counterId++), _sold(0), _archive(false){};
	~Product(){};

	Business		*bsn(){return _belongs_to;};
	vector<string>	trans(){return _transactions;};
	void			push_trans(string str){_transactions.push_back(str);_sold++;};
	void			print(){cout << "[" << _id << "] " << _name << " €" << _price << endl;};
	int				getPrice(){return _price;};
	string			getName(){return _name;};
	string			getBsn();
	string			getId(){return to_string(_id);};
	string			getSold(){return to_string(_sold);};

	bool			archive(){return _archive;};
	void			toggleArchive(){_archive = !_archive;};
	void			updateName(string name){_name = name;};
	void			updatePrice(unsigned int price){_price = price;}; //needs validation
};

#endif
