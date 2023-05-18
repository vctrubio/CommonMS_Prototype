#include "Appointment.hpp"

string    dateToString(time_t date)
{
    char dateTimeStr[100];
    strftime(dateTimeStr, sizeof(dateTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&date));
    return std::string(dateTimeStr);
}

vector<time_t>      generateRandomTimes()
{
    std::vector<time_t> randomTimes;
    
    time_t currentTime = time(nullptr);
    for (int i = 0; i < 4; ++i)
    {
        time_t randomTime = currentTime + (rand() % (3 * 24 * 60 * 60)); //NEEDS TO BE BETWEEN working hours....
        randomTimes.push_back(randomTime);
    }
    std::sort(randomTimes.begin(), randomTimes.end());
    std::cout << "Choose an appointment time:\n";
    for (int i = 0; i < 4; ++i)
    {
        char dateTimeStr[100];
        strftime(dateTimeStr, sizeof(dateTimeStr), "%d-%m-%Y %H:%M", localtime(&randomTimes[i]));
        std::cout << i + 1 << ". " << dateTimeStr << std::endl;
    }
    return randomTimes;
}

string	Appointment::csv()
{
	string str = to_string(_patient->id()) + "," + to_string(_doctor->id());
	return str;
}

void    Appointment::print()
{
    cout << *this;
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

bool surgeryPro() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    double probability = 4.0 / 5.0; // 4 out of 5 times the result is true
    
    return dis(gen) < probability;
}