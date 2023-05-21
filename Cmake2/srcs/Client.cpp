#include "../incl/Client.hpp"

Product*    Client::getProduct()
{
    Product *rtn;

    if (_cart.empty())
        return nullptr;
    
    rtn = _cart.front();
    _cart.erase(_cart.begin());
    return rtn;
}