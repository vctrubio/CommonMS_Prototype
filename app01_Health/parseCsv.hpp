#ifndef PARSECSV_HPP
#define PARSECSV_HPP

#include "Doctor.hpp"
#include "Patient.hpp"

class Doctor;
class Patient;

void	addtoCSV(int id, Doctor *d);
void	addtoCSV(int id, Patient *p);
bool	validateDoctor(vector<string> data);
#endif
