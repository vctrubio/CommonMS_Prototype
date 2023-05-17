#include "Doctor.hpp"

unsigned int Doctor::s_count = 1;

Doctor::Doctor(string name, Hospital *h):_name(name)
{
	_archive = false;
	_spc = UNKNOWN;
	_id = s_count++;
	h->addDoctor(this);
}

Doctor::Doctor(unsigned int id, string name, int spc, bool archived, Hospital *h):
_id(id), _name(name), _archive(archived)
{
	_spc = static_cast<speciality>(spc);
	h->addDoctor(this);
}

string	Doctor::rtnCsv()
{
	string str = to_string(_id);
	str += "," + _name + ",";
	str += to_string(_spc);
	str += ",";
	str += (_archive? "true" : "false");
	str += "\n";
	return str;
}