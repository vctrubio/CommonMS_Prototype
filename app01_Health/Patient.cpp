#include "Patient.hpp"

unsigned int Patient::s_count = 1;

string  Patient::rtnCsv()
{
    string str = to_string(_id) + "," + _name + "," + (_ingr? "true" : "false") + "," + (_archived? "true" : "false") + "\n";  
    return str;
}

