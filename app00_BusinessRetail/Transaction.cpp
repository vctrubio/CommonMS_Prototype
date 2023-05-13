#include "Transaction.hpp"


Transaction::Transaction(Business *bsn, Product *product, Client *client):_belongs_to(bsn), _product(product), _client(client)
{
	std::chrono::system_clock::time_point refTime = std::chrono::system_clock::now();

	std::time_t today_time = std::chrono::system_clock::to_time_t(refTime);
	std::tm* today_tm = std::localtime(&today_time);

	std::ostringstream oss;
	oss << std::put_time(today_tm, "%Y-%m-%d");
	_date = oss.str();

	_log = "Business: " + bsn->getName() + "| Sold: " + product->getName() + " €" + to_string(product->getPrice()) \
			+ "| to " + client->getName() + "| Date: " + _date + "\n";

	product->push_trans(_log);
	client->subtract(product->getPrice());
}
