#include "Business.hpp"

Business::Business(User *user, string name):_belongs_to(user), _name(name), _revenue(0)
{
	_belongs_to->updateBsn(this);
}



void Business::test()
{
	cout << "Testing Name: " << _belongs_to->getName() << endl;
	cout << "BSN NAME: " << _belongs_to->getBsn() << endl;

}

