#include "../incl/User.hpp"

unsigned int User::s_counterId = 1;

void	User::updateBsn(Business *bsn)
{
	if (_bsn == nullptr)
		_bsn = bsn;
	else
		cout << "Sorry, only 1 Business at a time.\n";
}

string	User::getBsn()
{
	return _bsn->getName();
}
