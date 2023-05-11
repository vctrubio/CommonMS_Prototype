#include "User.hpp"

unsigned int User::s_counterId = 1;


void	User::updateBsn(Business *bsn)
{
	if (_bsn == nullptr)
	{
		_bsn = bsn;
		//cout << "Business Updated Sucessfully\n";
	}
	else
		cout << "Sorry, only 1 Business at a time.\n";
	//cout << "(Update Business) to " << _bsn->getName() << endl;
}


string	User::getBsn()
{
	return _bsn->getName();
}
