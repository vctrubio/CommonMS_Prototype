#include "../incl/Appointment.hpp"

Appointment::Appointment(Doctor *doctor, Patient *patient, Room *room):_doctor(doctor), _patient(patient), _surgery(nullptr)
{
    if (!doctor || !patient || !room)
        return ;
    _status = false;
    int choice;
    vector<time_t>  times = generateRandomTimes();

    while (42)
    {
        cin >> choice;
        if (choice <= 4 && choice >= 1)
            break;
        cout << RED << "ERROR" << ENDC << " 1 2 3 or 4 \n";
    }
    _dateTime = times[choice - 1];
    dateTimeStr = dateToString(_dateTime);
    times.clear();
    room->addApp(this);
	cout << GREEN << "Appointment @ " << room->nb() << " => " << ENDC << patient->name() << " : DR." << doctor->name() << " : " << dateTimeStr << endl;
}

std::ostream& operator<<(std::ostream& os, Appointment& appointment) {
    os << "Patient: " << appointment.getPatient()->name() << std::endl;
    os << "Doctor: " << appointment.getDoctor()->name() << std::endl;
    os << "Time: " << appointment.getTime() << std::endl;
    os << "Status: " << (appointment.status() ? "Completed" : "Upcoming") << std::endl;
    return os;
}

string	Appointment::csv()
{
	string str = to_string(_patient->id()) + "," + to_string(_doctor->id());
	return str;
}

void    Appointment::complete()
{
    _status = true;
    if (surgeryPro())
    {
        cout << YELLOW << "Oops. " << ENDC << "DR. " << YELLOW << _doctor->name() << ENDC << " says " << _patient->name() << " needs surgery...\n";
        _surgery = new Surgery(_patient);
        _patient->baja();
    }
    else
    {
        cout << GREEN << " Appointment Completed\n" << ENDC ;
    }
}

void    Appointment::print()
{
    cout << *this;
}
