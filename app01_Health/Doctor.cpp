#include "Doctor.hpp"

unsigned int Doctor::s_count = 100;

Doctor::Doctor(string name, Hospital *h):_name(name)
{
	_archive = false;
	_spc = UNKNOWN;
	_id = s_count++;
	h->addDoctor(this);
}

Doctor::Doctor(unsigned int id, string name, speciality spc, bool archived, Hospital *h):
_id(id), _name(name), _spc(spc), _archive(archived)
{
	h->addDoctor(this);
}
