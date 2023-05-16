#include "Doctor.hpp"

unsigned int Doctor::s_count = 100;

Doctor::Doctor(string name, Hospital *h):_name(name)
{
	_archive = false;
	_spc = UNKNOWN;
	_id = s_count++;
	h->addDoctor(this);
}

